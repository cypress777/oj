#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<char> map;
vector<vector<int>> graph;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            map.push_back(ch);
        }
    }

    // build graph
    graph = vector<vector<int>>(N * M * 4, vector<int>());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int id = i * M + j;
            char div = map[id];
            for (int k = 0; k < 4; k++) {
                for (int kk = 0; kk < 4; kk++) {
                    if (k == kk ||
                        div == '/' &&
                        ((k == 0 && kk == 3 || k == 3 && kk == 0) || (k == 1 && kk == 2 || k == 2 && kk == 1)) ||
                        div == '\\' &&
                        ((k == 0 && kk == 1 || k == 1 && kk == 0) || (k == 3 && kk == 2 || k == 2 && kk == 3)))
                        continue;
                    graph[id + k].push_back(id + kk);
                }
                if (k == 0) {
                    if (i != 0) graph[id + k].push_back(((i - 1) * M + j) * 4 + 2);
                } else if (k == 1) {
                    if (j != 0) graph[id + k].push_back((i * M + j - 1) * 4 + 3);
                } else if (k == 2) {
                    if (i != N - 1) graph[id + k].push_back(((i + 1) * M + j) * 4);
                } else if (k == 3) {
                    if (j != M - 1) graph[id + k].push_back((i * M + j + 1) * 4 + 1);
                }
            }
        }
    }

    return 0;
}

