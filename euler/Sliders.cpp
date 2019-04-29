#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> value;
int MOD = 10000007;

int encode(const vector<int> &map, int id) {
    int code = 0;
    for (int i = 0; i < map.size(); i++) {
        if (map[i] == 1) code |= (1UL << i);
    }

    code |= (id << 16);
    return code;
}

void decode(int code, vector<int> & map, int &id) {
    map = vector<int>(16);
    for (int i = 0; i < 16; i++) {
        if (code & (1UL << i)) map[i] = 1;
    }
    id = (code >> 16);
}

int get_next(int code , int dir) {
    vector<int> map;
    int id;
    decode(code, map, id);

    vector<int> nmap = map;
    int nid = -1;
    if (dir == 0) {
        if (nid / 4 == 0) nid = -1;
        else nid = id - 4;
    } else if (dir == 1) {
        if (nid % 4 == 3) nid = -1;
        else nid = id + 1;
    } else if (dir == 2) {
        if (nid / 4 == 3) nid = -1;
        else nid = id + 4;
    } else if (dir == 3) {
        if (nid %4 == 0) nid = -1;
        else nid = id - 1;
    }

    if (nid >= 0) {
        nmap[id] = map[nid];
        nmap[nid] = 0;
        return encode(nmap, nid);
    }
    return -1;
}

void show(int code) {
    if (code == -1) {
        cout << "map: none id: " << -1 << endl;
        return;
    }
    vector<int> map;
    int id;
    decode(code, map, id);
    cout << "map: ";
    for (int i = 0; i < 16; i++) cout << map[i] << " ";
    cout << "id: " << id << endl;
}

int main() {
    vector<int> start_map(16);
    for (int i = 0; i <  4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j > 1) start_map[i * 4 + j] = 1;
        }
    }
    int start_code = encode(start_map, 0);
    show(start_code);

    vector<int> end_map(16);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) end_map[i * 4 + j] = 1;
        }
    }
    int end_code = encode(end_map, 0);
    show(end_code);

    queue<int> que;
    que.push(start_code);
    unordered_map<int, long long> vst;
    vst[start_code] = 0;

    value = {68, 76, 85, 82};

    while (!que.empty()) {
        int code = que.front();
        que.pop();
        cout << "que size: " << que.size() << " code: " << code << " code val: " << vst[code] << " ";
        show(code);
        cout << "next: " << endl;
        for (int i = 0; i < 4; i++) {
            cout << "111" << endl;
            int next_code = get_next(code, i);
            cout << "2222" << endl;
            if (next_code == end_code) {
                cout << "result: " << ((vst[code] * 243 + value[i]) % MOD) << endl;
                return 0;
            }
            cout << "333" << endl;
            show(next_code);
            vst.find(next_code);
            cout << "+++" << endl;
            if (next_code >= 0 && vst.find(next_code) == vst.end()) {
                cout << "777" << endl;
                vst[next_code] = (vst[code] * 243 + value[i]) % MOD;
                cout << "666" << endl;
                que.push(next_code);
                cout << "555" << endl;
            }
            cout << "4444" << endl;
        }
        cout << "222" << endl;
    }

    return 0;
}

