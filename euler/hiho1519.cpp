#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    int S, T;
    cin >> N >> M;

    auto id = [&M](int x, int y) { return y * M + x; };

    vector<int> matrix(N * M, 0);
    for (int y = 0; y < N; y++) {
        string symbols;
        cin >> symbols;
        for (int x = 0; x < M; x++) {
            char symbol = symbols[x];
            if (symbol == '.') {
                matrix[id(x, y)] = 1;
            } else if (symbol == 'T') {
                matrix[id(x, y)] = 666;
                T = id(x, y);
            } else if (symbol == 'S') {
                matrix[id(x, y)] = 777;
                S = id(x, y);
            }
        }
    }

    auto pass = [&N, &M, &T, &matrix, &id](int x, int y) {
        if (x < 0 || y < 0 || x >= M || y >= N) return false;
        if (matrix[id(x, y)] == 0) return false;
        if (id(x, y) == T) return false;
        return true;
    };

    // cout << "matrix: " << endl;
    // for (int y = 0; y < N; y++) {
    //     for (int x = 0; x < M; x++) {
    //         cout << matrix[id(x, y)] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    vector<vector<int>> graph(N * M, vector<int>());
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            if (matrix[id(x, y)] == 0) continue;
            int xx, yy;
            for (int k = 0; k < 4; k++) {
                xx = x + dx[k];
                yy = y + dy[k];
                while (pass(xx, yy)) {
                    xx += dx[k];
                    yy += dy[k];
                }
                if (xx < 0 || yy < 0 || xx >= M || yy >= N || id(xx, yy) != T) {
                    xx -= dx[k];
                    yy -= dy[k];
                }
                if (xx != x || yy != y)
                    graph[id(x, y)].push_back(id(xx, yy));
            }
        }
    }

    // cout << S << ' ' << T << endl;
    // cout << "graph: " << endl;
    // for (int i = 0; i < M * N; i++) {
    //     cout << i << ": ";
    //     for (int j : graph[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> path(N * M, -1);
    path[S] = 0;

    vector<int> que;
    vector<int> vst(N * M, 0);
    que.push_back(S);
    vst[S] = -1;
    int r = 0, f = 0;
    while (r <= f) {
        int cur = que[r];
        r++;
        for (int pos : graph[cur]) {
            if (vst[pos] != -1) {
                vst[pos] = -1;
                que.push_back(pos);
                path[pos] = path[cur] + 1;
                if (pos == T) {
                    path[pos] -= 1;
                    break;
                }
                f++;
            }
        }
    }

    cout << path[T] << endl;
}