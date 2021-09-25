#include<vector>;
using namespace std;


class Solution {

int N;
vector<vector<int>> grid;
vector<vector<int>> visit;
vector<vector<int>> queue;
vector<int> steps;
int head = 0, tail = -1;

vector<int> dx = {1, 1, 0, -1, -1, 0, 1, -1};
vector<int> dy = {0, 1, 1, 0, -1, -1, -1, 1};

int bfs() {
    N = grid.size();
    visit = vector<vector<int>>(N, vector<int>(N, 0));

    if (grid[0][0] == 1) return -1;
    if (N == 1) return 1;

    queue = {{0, 0}};
    visit[0][0] = 1;
    tail = 0;
    steps = {1};

    while (head <= tail) {
        int x = queue[head][0], y = queue[head][1];
        int step = steps[head];
        head++;

        for (int i = 0; i < dx.size(); i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (grid[nx][ny] == 0 && visit[nx][ny] == 0) {
                visit[nx][ny] = 1;

                if (nx == N - 1 && ny == N - 1) return step + 1;

                queue.push_back({nx, ny});
                steps.push_back(step + 1);
                
                tail++;
            }
        }
    }

    return -1;
}

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        this->grid = grid;

        return bfs();
    }
};