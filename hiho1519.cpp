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
    auto id = [&N](int x, int y) { return y * N + x; };

    vector<int> matrix(N * M, 0);
    for (int y = 0; y < M; y++) {
        string symbols;
        cin >> symbols;
        for (int x = 0; x < N; x++) {
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

    cout << "S: " << S << " T: " << T << endl;

    cout << "matrix: " << endl;
    for (int i = 0; i < N * M; i++) {
        cout << matrix[i] << " ";
    }
    cout << endl;
    
    vector<vector<int>> graph(N * M, vector<int>());
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cout << ">> " << id(x, y) << " " << x << " " << y << endl;
            if (matrix[id(x, y)] == 0) continue;
            int xx, yy;

            xx = x - 1;
            while (xx > 0 && matrix[id(xx, y)] != 0 && id(xx, y) != T) --xx;
            if (id(xx, y) != T) xx++;
            if (xx != x)
                graph[id(x, y)].push_back(id(xx, y));
            xx = x + 1;
            while (xx < N && matrix[id(xx, y) != 0] && id(xx, y) != T) ++xx;
            if (id(xx, y) != T) xx--;
            if (xx != x)
                graph[id(x, y)].push_back(id(xx, y));

            yy = y - 1;
            while (yy > 0 && matrix[id(x, yy)] != 0 && id(x, yy) != T) --yy;
            if (id(x, yy) != T) yy++;
            if (yy != y)
                graph[id(x, y)].push_back(id(x, yy));
            yy = y + 1;
            while (yy < M && matrix[id(x, yy)] != 0 && id(x, yy - 1) != T) ++yy;
            if (id(x, yy) != T) yy--;
            if (yy != y)
                graph[id(x, y)].push_back(id(x, yy));

            cout << "to: " << endl;
            for (int t : graph[id(x, y)]) {
                cout <<  t << " ";
            }
            cout << endl;
        }
    }

    return 0;
    vector<int> path(N * M, -1);
    path[S] = 0;

    vector<int> que;
    vector<int> vst(N * M, 0);
    que.push_back(S);
    vst[T] = -1;
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
                    cout << path[pos] <<  endl;
                    break;
                }
                f++;
            }
        }
    }
}