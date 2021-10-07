#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> path;
    vector<vector<int>> graph;
    vector<vector<int>> visit;
    vector<string> airports;
    vector<vector<string>> tickets;
    unordered_map<string, int> str2int;

    void dfs(int cur) {
        sort(graph[cur].begin(), graph[cur].end());

        for (int nei : graph[cur]) {
            if (visit[cur][nei] > 0) {
                visit[cur][nei]--;

                dfs(nei);
            }
        }
        path.push_back(cur);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        this->tickets = tickets;

        set<string> airports_set;
        for (auto ticket : tickets) {
            airports_set.insert(ticket[0]);
            airports_set.insert(ticket[1]);
        }

        for (auto airport : airports_set) airports.push_back(airport);
        sort(airports.begin(), airports.end());

        for (int i = 0; i < airports.size(); i++) str2int.insert({airports[i], i});

        graph = vector<vector<int>>(airports.size(), vector<int>{});
        visit = vector<vector<int>>(airports.size(), vector<int>(airports.size(), 0));
        for (auto ticket : tickets) {
            int from = str2int[ticket[0]], to = str2int[ticket[1]];
            graph[from].push_back(to);
            visit[from][to]++;
        }

        int start = str2int["JFK"];
        dfs(start);

        vector<string> result;
        for (int i = path.size() - 1; i >= 0; i--) {
            auto airport = airports[path[i]];
            result.push_back(airport);
        }

        return result;
    }
};