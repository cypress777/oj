#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses, 0);

        for (auto order: prerequisites) {
            graph[order[1]].push_back(order[0]);
            indegrees[order[0]]++;
        }

        queue<int> que;
        
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                que.push(i);
            }
        }

        auto result = vector<int>{};

        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            result.push_back(cur);

            for (int nei : graph[cur]) {
                indegrees[nei]--;
                if (indegrees[nei]==0) que.push(nei);
            }
        }

        if (result.size() != numCourses) return vector<int>{};
        return result;
    }
};
