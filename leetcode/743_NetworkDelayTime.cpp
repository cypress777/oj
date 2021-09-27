#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node
{
    int point, dist;
};

bool operator<(const Node& a, const Node& b) {
    return a.dist > b.dist;
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k = k - 1;
        
        vector<vector<Node>> graph(n);
        for (auto time : times) {
            graph[time[0] - 1].push_back({.point = time[1] - 1, .dist = time[2] });
        }

        priority_queue<Node> pq{};
        vector<bool> visit(n, false);
        vector<int> dist(n, INT_MAX);
        vector<int> last(n, -1);
        pq.push({k, 0});
        dist[k] = 0;
        int result = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (visit[cur.point]) continue;

            result = max(result, cur.dist);
            visit[cur.point] = true;
            // cout << "----"  << cur.point << " " << cur.dist << " " << result << endl;

            for (Node nei : graph[cur.point]) {
                if (!visit[nei.point]) {
                    int new_dist = cur.dist + nei.dist;
                    if (new_dist < dist[nei.point]) {
                        dist[nei.point] = new_dist;
                        last[nei.point] = cur.point;
                        pq.push({nei.point, new_dist});
                    }
                }
            }
        }

        for (bool v : visit) {
            if (!v) return -1;
        }

        return result;
    }
};