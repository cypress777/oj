#include <vector>
#include <iostream>

using namespace std;

int N, M, K;
int total_h, total_a;
int HP, AP;
vector<vector<int>> h_map;
vector<vector<int>> a_map;
vector<vector<int>> slate_map;
vector<vector<int>> special_monsters_id;
vector<vector<int>> monsters_id;

int main() {
    cin >> N >> M;

    slate_map = vector<vector<int>>(N, vector<char>(M, 0));
    h_map = vector<vector<int>>(N, vector<char>(M, 0));
    a_map = vector<vector<int>>(N, vector<char>(M, 0));
    special_monsters_id = vector<int>();
    monsters_id = vector<int>();
    K = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            if (ch == "S") {
                K++;
                special_monsters_id.push_back(i * M + j);
                monsters_id.push_back(i * M + j);
            } else if (ch == "M") {
                K++;
                monsters_id.push_back(i * M + j);
            }
        }
    }

    total_a = 0;
    total_h = 0;
    for (int i = 0; i < K; i++) {
        int id = monsters_id[i];
        int r = id / M;
        int c = id % M;

        int h, a;
        cin >> h >> a;
        h_map[r][c] = h;
        a_map[r][c] = a;
        total_a += a;
        total_h += h;
    }

    cin >> HP >> AP;

    return 0;
}
