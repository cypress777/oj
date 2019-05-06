#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int N, M, K;
int total_h, total_a;
int HP, AP;
vector<int> h_map;
vector<int> a_map;
int monsters_code;
int special_monsters_code;

int encode(const vector<int> &map, int buff) {
    int code = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int id = i * M + j;
            if (map[id] == 1) code |= (1 << id);
        }
    }
    code |= (buff << 20);
    return code;
}

void decode(int code, vector<int> &map) {
    map = vector<int>(N * M, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int id = i * M + j;
            if (code & (1 << id)) map[id] = 1;
        }
    }
}

int get_buff(int code) {
    return int(code >> 20);
};

struct State {
    explicit State() {};
    State(int code, int hp) : code_(code), hp_(hp) {}
    int code_;
    int hp_;
};

struct PQue {
    explicit PQue() : r_(0), f_(1) {
        heap_ = vector<State>(1, State());
    }

    State pop() {
        State state = heap_[f_];
        heap_[f_] = heap_[r_];
        r_--;
        index_[heap_[f_].code_] = f_;
        down(f_);
        return state;
    }

    void update(State state) {
        if (index_.find(state.code_) == index_.end()) {
            r_++;
            if (heap_.size() > r_) heap_[r_] = state;
            else heap_.push_back(state);
            index_[state.code_] = r_;
            up(r_);
        } else {
            if (heap_[index_[state.code_]].hp_ < state.hp_) {
                heap_[index_[state.code_]] = state;
                up(index_[state.code_]);
            }
        }
    }

    void up(int id) {
        while (id > 1) {
            if (heap_[id].hp_ <= heap_[id / 2].hp_) break;

            State tmp;
            tmp = heap_[id];
            heap_[id] = heap_[id / 2];
            heap_[id / 2] = tmp;
            index_[heap_[id].code_] = id;
            index_[heap_[id / 2].code_] = id / 2;
            id /= 2;
        }
    }

    void down(int id) {
        while (id < r_) {
            int new_id = id;
            if (id * 2 <= r_ && heap_[new_id].hp_ < heap_[id * 2].hp_) new_id = id * 2;
            if (id * 2 + 1 <= r_ && heap_[new_id].hp_ < heap_[id * 2].hp_) new_id = id * 2 + 1;
            if (new_id == id) break;

            State tmp;
            tmp = heap_[id];
            heap_[id] = heap_[new_id];
            heap_[new_id] = tmp;
            index_[heap_[id].code_] = id;
            index_[heap_[new_id].code_] = new_id;

            id = new_id;
        }
    }

    bool empty() {
        return f_ > r_;
    }

    vector<State> heap_;
    unordered_map<int, int> index_;
    int r_, f_;
};

int main() {
    cin >> N >> M;

    h_map = vector<int>(N * M, 0);
    a_map = vector<int>(N * M, 0);
    K = 0;
    monsters_code = 0;
    special_monsters_code = 0;
    int start_code = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            if (ch == 'D') start_code |= (1 << (i * M + j));
            if (ch == 'S') {
                K++;
                special_monsters_code |= (1 << (i * M + j));
                monsters_code |= (1 << (i * M + j));
            } else if (ch == 'M') {
                K++;
                monsters_code |= (1 << (i * M + j));
            }
        }
    }
    start_code |= (5 << 20);

    total_a = 0;
    total_h = 0;
    int id = 0;
    while (id < N * M) {
        if (!monsters_code & (1 << id)) {
            id++;
            continue;
        }

        int h, a;
        cin >> h >> a;
        h_map[id] = h;
        a_map[id] = a;
        total_a += a;
        total_h += h;
        id++;
    }

    cin >> HP >> AP;

    PQue pque;
    pque.update(State(start_code, HP));

    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {1, 0, -1, 0};
    while (!pque.empty()) {
        State state = pque.pop();
        if ((!state.code_ & monsters_code) == 0) {
            cout << state.hp_ << endl;
            return 0;
        }
        vector<int> map;
        decode(state.code_, map);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int new_id = i * M + j;

                if (map[new_id] == 1) continue;

                bool has_adj = false;
                for (int k = 0; k < 4; k++) {
                    int ii = i + di[k];
                    int jj = j + dj[k];
                    if (map[ii * M + jj] == 1) {
                        has_adj = true;
                        break;
                    }
                }
                if (!has_adj) continue;

                vector<int> new_map = map;
                new_map[new_id] = 1;
                int new_buff = get_buff(state.code_);
                int new_hp = state.hp_;
                int monster_hp = h_map[new_id];
                int monster_ap = a_map[new_id];
                while (monster_hp > 0) {
                    monster_hp -= AP;
                    if (new_buff > 0) {
                        new_buff--;
                    } else {
                        new_hp -= monster_ap;
                    }
                }
                if ((1 << new_id) & special_monsters_code) new_buff = 5;

                if (new_hp < 0) continue;

                int new_code = encode(new_map, new_buff);
                State new_state(new_code, new_hp);
                pque.update(new_state);
            }
        }
    }

    return 0;
}
