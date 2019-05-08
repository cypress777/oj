#include <vector>
#include <iostream>
#include <unordered_map>
#include <stdio.h>

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

void show_code(int code) {
    vector<int> map;
    decode(code, map);
    cout << "----------------------" << endl;
    cout << "code: " << code << endl;
    cout << "buff: " << int(code >> 20) << endl;
    cout << "map: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i * M + j] << " ";
        }
        cout << endl;
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

bool has_adj(State state, int id) {
    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {1, 0, -1, 0};

    int i = id / M;
    int j = id % M;

    bool has_adj = false;
    for (int k = 0; k < 4; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];
        int nid = ii * M + jj;
        if (state.code_ & (1 << nid)) {
            has_adj = true;
            break;
        }
    }
    return has_adj;
}

State get_next_state(int new_id, State old_state) {
    vector<int> new_map;
    decode(old_state.code_, new_map);
    new_map[new_id] = 1;
    int new_buff = get_buff(old_state.code_) - 1;
    int new_hp = old_state.hp_;

    int monster_hp = h_map[new_id];
    int monster_ap = a_map[new_id];

    while (monster_hp > 0) {
        monster_hp -= AP;
        if (new_buff >= 0) {
            new_buff--;
        } else {
            new_hp -= monster_ap;
        }
    }

    if (new_buff < 0) new_buff = 0;
    if ((1 << new_id) & special_monsters_code) new_buff = 5;

    int new_code = encode(new_map, new_buff);

    State new_state(new_code, new_hp);
    return new_state;
}

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
        if (!(monsters_code & (1 << id))) {
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

    while (!pque.empty()) {
        State state = pque.pop();

        if ((~state.code_ & monsters_code) == 0) {
            cout << "             Result:" << endl;
            show_code(state.code_);
            cout << "hp: " << state.hp_ << endl;
            return 0;
        }

        vector<int> map;
        decode(state.code_, map);
        int buff = get_buff(state.code_);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int new_id = i * M + j;
                if ((state.code_ & (1 << new_id)) || !has_adj(state, new_id)) continue;

                State new_state = get_next_state(new_id, state);
                if (new_state.hp_ < 0) continue;

                pque.update(new_state);

                for (int ii = 0; ii < N; ii++) {
                    for (int jj = 0; jj < M; jj++) {
                        int next_id = ii * M + jj;
                        if ((new_state.code_ & (1 << next_id)) || !has_adj(new_state, next_id)) continue;

                        State next_state = get_next_state(next_id, new_state);
                        if (pque.index_.find(next_state.code_) != pque.index_.end() &&
                            pque.heap_[pque.index_[next_state.code_]].hp_ < next_state.hp_) {
                            pque.update(next_state);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
