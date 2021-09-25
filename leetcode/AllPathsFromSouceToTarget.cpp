#include<vector>;

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

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->Graph = graph;
        N = graph.size(), S = 0, E = N - 1;
        All = vector<vector<int>>();
        visit = vector<int>(N, 0);

        dfs(S, vector<int>());

        return All;
    }
};