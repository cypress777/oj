#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<char> map;
vector<vector<int>> graph;

vector<int> vst;

int main() {
    cin >> N >> M;
    string s;
    getline(cin, s);
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        for (int j = 0; j < M; j++) {
            map.push_back(s[j]);
        }
    }

    // build graph
    graph = vector<vector<int>>(N * M * 4, vector<int>());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int box_id = i * M + j;
            char div = map[box_id];
            for (int k = 0; k < 4; k++) {
                int id = box_id * 4 + k;
                for (int kk = 0; kk < 4; kk++) {
                    if (k == kk ||
                        div == '/' &&
                        ((k == 0 && kk == 3 || k == 3 && kk == 0) || (k == 1 && kk == 2 || k == 2 && kk == 1) ||
                         (k == 0 && kk == 2 || k == 2 && kk == 0) || (k == 1 && kk == 3 || k == 3 && kk == 1)) ||
                        div == '\\' &&
                        ((k == 0 && kk == 1 || k == 1 && kk == 0) || (k == 3 && kk == 2 || k == 2 && kk == 3) ||
                         (k == 0 && kk == 2 || k == 2 && kk == 0) || (k == 1 && kk == 3 || k == 3 && kk == 1)))
                        continue;
                    graph[id].push_back(box_id * 4 + kk);
                }
                if (k == 0) {
                    if (i != 0) graph[id].push_back(((i - 1) * M + j) * 4 + 2);
                } else if (k == 1) {
                    if (j != 0) graph[id].push_back((i * M + j - 1) * 4 + 3);
                } else if (k == 2) {
                    if (i != N - 1) graph[id].push_back(((i + 1) * M + j) * 4);
                } else if (k == 3) {
                    if (j != M - 1) graph[id].push_back((i * M + j + 1) * 4 + 1);
                }
            }
        }
    }

//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            for (int k = 0; k < 4; k++) {
//                cout << "----- " << (i * M + j) * 4 + k << "  " << i << " " << j << " " << k << endl;
//                for (int id : graph[(i * M + j) * 4 + k]) cout << id << " ";
//                cout << endl;
//            }
//        }
//    }

    vst = vector<int>(N * M * 4, 0);
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int new_id = (i * M + j) * 4 + k;
                if (vst[new_id] == 1) continue;

//                cout << count << " " << i << " " << j << " " << k << endl;
                count++;
                vst[new_id] = 1;

                vector<int> que(1, new_id);
                int r = 0;

                while (r < que.size()) {
                    int id = que[r];
                    r++;

                    for (int nid : graph[id]) {
                        if (vst[nid] == 1) continue;
                        vst[nid] = 1;
                        que.push_back(nid);
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
