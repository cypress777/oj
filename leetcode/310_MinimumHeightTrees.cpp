#include<vector>
#include<queue>

using namespace std;


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return vector<int>{0};
        
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n, vector<int>{});
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        vector<int> que;
        vector<int> height;
        int front = 0, end = -1;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                que.push_back(i);
                height.push_back(1);
                end++;
            }
        }

        while (front <= end) {
            int n = que[front];
            int h = height[front];
            front++;

            degree[n]--;

            for (int nei : graph[n]) {
                degree[nei]--;

                if (degree[nei] == 1) {
                    que.push_back(nei);
                    height.push_back(h + 1);
                    end++;
                }
            }
        }

        vector<int> result;
        for (int i = n - 1; i >= 0; i--) {
            if (height[i] < height[n - 1]) break;
            result.push_back(que[i]);
        }

        return result;
    }
};