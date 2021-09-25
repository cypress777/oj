#include<vector>;
#include<algorithm>;
using namespace std;


class Solution {

vector<vector<int>> Graph;
int S, E, N;
vector<vector<int>> All;
vector<int> visit;

void dfs(int n, vector<int> path) {
    visit[n] = 1;
    path.push_back(n);

    if (n == E) {
        All.push_back(path);
    } else {
        for (int next : Graph[n]) {
            if (visit[next] == 0) dfs(next, path);
        }
    }

    visit[n] = 0;
}

vector<vector<int>> queue;
int head, tail;

void bfs() {
    queue = vector<vector<int>>({{S}});
    visit[S] = 1;
    head = 0, tail = 0;

    while (head <= tail) {
        auto cur = queue[head];
        head++;

        for (int next : Graph[cur[cur.size() - 1]]) {
            if (find(cur.begin(), cur.end(), next) == cur.end()) {
                auto new_path = cur;
                new_path.push_back(next);

                if (next == E) {
                    All.push_back(new_path);
                } else {
                    queue.push_back(new_path);
                    tail++;
                }
            }
        }
    }
}

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->Graph = graph;
        N = graph.size(), S = 0, E = N - 1;
        All = vector<vector<int>>();
        visit = vector<int>(N, 0);

        // dfs(S, vector<int>());

        bfs();

        return All;
    }
};