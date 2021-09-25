#include<vector>
using namespace std;


class Solution {

vector<int> Flag;
vector<vector<int>> Edges;
int N, S, E;

bool dfs(int x) {
    Flag[x] = 1;

    if (x == E) return true;

    for (int i = 0; i < Edges[x].size(); i++) {
        int y = Edges[x][i];
        if (Flag[y] == 0) {
            if (dfs(y)) return true;
        }
    }

    return false;
}

bool bfs() {
    vector<int> queue({S});
    Flag[S] = 1;
    int head = 0, tail = 0;

    while (head <= tail) {
        int cur = queue[head];
        head++;

        if (cur == E) return true;

        for (int next : Edges[cur]) {
            if (Flag[next] == 0) {
                queue.push_back(next);
                Flag[next] = 1;
                tail++;
            }
        }
    }

    return false;
}

public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        N = n, S = start, E = end;

        Edges = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1];
            Edges[x].push_back(y);
            Edges[y].push_back(x);
        }

        Flag = vector<int>(n, 0);

        // return dfs(start);
        return bfs();
    }
};