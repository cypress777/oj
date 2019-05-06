#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int N, M, K;
int total_h, total_a;
int HP, AP;
vector<vector<int>> h_map;
vector<vector<int>> a_map;
int monsters_code;
int special_monsters_code;

int encode(const vector<int> &map) {
}

void decode(int code, vector<int> &map) {

}

struct Code {
    Code(int code, int hp) : code_(code), hp_(hp) {}
    int code_;
    int hp_;
};

struct PQue {
    PQue() r(0), f(-1) {}

    Code pop() {

    }

    void insert(Code code) {

    }

    void up(int id) {

    }

    void down(int id) {

    }

    bool empty() {
        return r_ > f_;
    }

    vector<int> heap_;
    int r_, f_;
};

int main() {
    cin >> N >> M;

    h_map = vector<int>(N * M, 0);
    a_map = vector<int>(N * M, 0);
    special_monsters_id = vector<int>();
    monsters_id = vector<int>();
    K = 0;
    monster_code = 0;
    special_monsters_code = 0;
    int start_code = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            if (ch == "D") start_code |= (1 << (i * M + j));
            if (ch == "S") {
                K++;
                special_monsters_code |= (1 << (i * M + j));
                monsters_code |= (1 << (i * M + j));
            } else if (ch == "M") {
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

    unordered_map<int, int> reachable;
    PQue pque();
    pque().insert(Code(start_code, HP));
    reachable[start_code] = 0;

    while (!pque.empty()) {
        Code code = pque().pop();
    }

    return 0;
}
