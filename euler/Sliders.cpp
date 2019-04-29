#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> value;
int MOD = 100000007;
int LEN = 4;

int encode(const vector<int> &map, int id) {
    int code = 0;
    for (int i = 0; i < LEN * LEN; i++) {
        if (map[i] == 1) code |= (1UL << i);
    }

    code |= (id << LEN * LEN);
    return code;
}

void decode(int code, vector<int> &map, int &id) {
    map = vector<int>(LEN * LEN, 0);
    for (int i = 0; i < 16; i++) {
        if (code & (1UL << i)) map[i] = 1;
    }
    id = (code >> LEN * LEN);
}

void show(int code) {
    if (code == -1) {
        cout << "code: " << -1 << endl;
        return;
    }

    vector<int> map;
    int id;
    decode(code, map, id);
    cout << "code: " << code << " map: " << endl;
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (i * LEN + j == id) cout << "+ ";
            else cout << map[i * LEN + j] << " ";
        }
        cout << endl;
    }

}

int main() {
    vector<int> start_map(LEN * LEN, 0);
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (j > 1) start_map[i * LEN + j] = 1;
        }
    }
    int start_code = encode(start_map, 0);
    show(start_code);

    vector<int> end_map(LEN * LEN, 0);
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) end_map[i * LEN + j] = 1;
        }
    }
    int end_code = encode(end_map, 0);
    show(end_code);

    queue<int> que;
    que.push(start_code);
    unordered_map<int, long long> vst;
    vst[start_code] = 0;

    value = {68, 76, 85, 82};

    int n = 1;
    vector<int> states;
    states.push_back(start_code);

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while (!que.empty()) {
        int code = que.front();
        que.pop();

        cout << "-------" << endl;
        show(code);

        vector<int> map;
        int id;
        decode(code, map, id);
        int x = id / LEN;
        int y = id % LEN;

        cout << "next: " << endl;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= LEN || ny < 0 || ny >= LEN) continue;

            int nid = nx * LEN + ny;
            vector<int> nmap = map;
            nmap[nid] = 0;
            nmap[id] = map[nid];
            int next_code = encode(nmap, nid);
            show(next_code);

            if (next_code == end_code) {
                cout << "result: " << ((vst[code] * 243 + value[i]) % MOD) << endl;
                return 0;
            }

            if (next_code >= 0 && vst.find(next_code) == vst.end()) {
                vst[next_code] = (vst[code] * 243 + value[i]) % MOD;
                que.push(next_code);
                n++;
                states.push_back(next_code);
            }
        }
    }

    return 0;
}

