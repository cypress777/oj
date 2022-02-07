#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


struct Flight
{
    int point, cost, step;
};

bool operator<(const Flight& a, const Flight& b) {
    return a.cost > b.cost;
}

bool valuable(const vector<Flight>& hist, Flight flight) {
    for (auto h : hist) {
        if (flight.step >= h.step && flight.cost >= h.cost) return false;
    }
    return true;
}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<Flight>> graph(n, vector<Flight>());
        for (auto route : flights) {
            graph[route[0]].push_back({.point = route[1], .cost = route[2], .step = 0});
        }

        priority_queue<Flight> pq{};
        pq.push({.point = src, .cost = 0, .step = 0 });

        vector<vector<Flight>> dist(n);
        vector<int> last(n, -1);

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if (cur.point == dst) return cur.cost;

            if (cur.step > k + 1) continue;
            if (!valuable(dist[cur.point], cur)) continue;
            dist[cur.point].push_back(cur);

            for (auto nei : graph[cur.point]) {
                int new_cost = cur.cost + nei.cost;
                int new_step = cur.step + 1;
                if (new_step > k + 1) continue;

                Flight new_flight{.point = nei.point, .cost = new_cost, .step = new_step};
                if (valuable(dist[new_flight.point], new_flight)) pq.push(new_flight);
            }
        }

        return -1;
    }
};