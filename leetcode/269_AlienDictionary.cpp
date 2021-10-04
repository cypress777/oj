#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<bool> selected(26, false);
        int selected_num = 0;
        for (auto word : words) {
            for (auto letter : word) 
            {
                if (!selected[letter - 'a']) selected_num++;
                selected[letter - 'a'] = true;
            }
        }

        vector<vector<int>> graph(26, vector<int>{});
        vector<int> in_degree(26, 0);
        for (int i = 1; i < words.size(); i++) {
            bool found = false;
            for (int j = 0; j < min(words[i - 1].size(), words[i].size()); j++) {
                if (words[i - 1][j] != words[i][j]) {
                    graph[words[i - 1][j] - 'a'].push_back(words[i][j] - 'a');
                    in_degree[words[i][j] - 'a']++;
                    found = true;
                    break;
                }
            }
            if (!found && words[i - 1].size() > words[i].size()) {
                return "";
            }
        }

        queue<int> que;
        vector<bool> visit(26, false);
        for (int i = 0; i < in_degree.size(); i++) {
            if (selected[i] && in_degree[i] == 0) que.push(i);
        }

        string result = "";
        while(!que.empty()) {
            int cur = que.front();
            que.pop();

            if (visit[cur]) continue;
            visit[cur] = true;

            result.push_back('a' + cur);

            for (int next : graph[cur]) {
                if (!visit[next]) {
                    in_degree[next]--;
                    if (in_degree[next] == 0) que.push(next);
                }
            }
        }

        if (result.size() != selected_num) return "";
        return result;
    }
};