#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Edge {
  int dist, x, y;
};

bool operator<(const Edge& a, const Edge& b) {
    return a.dist > b.dist;
};

class Solution {

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<Edge> pq;
        int size = points.size();

        vector<bool> visited(size, false); 
        visited[0] = true;
        for (int i = 1; i < size; i++) {
            int dist = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
            pq.push({.dist = dist, .x = 0, .y = i});
        }

        int cnt = 0;
        int result = 0;
        while (!pq.empty()) {
            if (cnt == size - 1) break;
            auto next = pq.top();
            pq.pop();
            if (!visited[next.y]) {
                visited[next.y] = true;
                result += next.dist;
                cnt++;

                for (int i = 0; i < size; i++) {
                    if (!visited[i]) {
                        int dist = abs(points[next.y][0] - points[i][0]) + abs(points[next.y][1] - points[i][1]);
                        pq.push({.dist = dist, .x = next.y, .y = i});
                    }
                }
            }
        }

        return result;
    }
};