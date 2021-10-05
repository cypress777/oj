#include<vector>
#include<string>
#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> result;
    unordered_map<string, int> map;
    vector<vector<int>> graph;
    vector<vector<bool>> visit;
    vector<vector<string>> tickets;
    vector<string> airports;

    void dfs(int start, vector<int>& path, int size = 0) {
        if (result.size() > 0) return;

        if (size == tickets.size() + 1) {
            for (int i = 0; i < size; i++) {
                result.push_back(airports[path[i]]);
            }
            return;
        }

        for (int i = 0; i < graph[start].size(); i++) {
            if (!visit[start][i]) {
                int dest = graph[start][i];
                // cout << dest << " " << airports[dest] << endl;

                visit[start][i] = true;
                path[size] = dest;

                dfs(dest, path, size + 1);

                visit[start][i] = false;
            }
        }
    };

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        this->tickets = tickets;

        set<string> found;
        for (auto ticket : tickets) {
            if (found.find(ticket[0]) == found.end()) {
                airports.push_back(ticket[0]);
                found.insert(ticket[0]);
            }
            if (found.find(ticket[1]) == found.end()) {
                airports.push_back(ticket[1]);
                found.insert(ticket[1]);
            }
        }

        sort(airports.begin(), airports.end());
        for (int i = 0; i < airports.size(); i++) {
            map.insert({airports[i], i});
        }

        graph = vector<vector<int>>(airports.size(), vector<int>());
        visit = vector<vector<bool>>(airports.size(), vector<bool>());
        for (auto ticket : tickets) {
            graph[map[ticket[0]]].push_back(map[ticket[1]]);
            visit[map[ticket[0]]].push_back(false);
        }

        for (int i = 0; i < graph.size(); i++) {
            sort(graph[i].begin(), graph[i].end());
        }
        
        // for (int i = 0; i < graph.size(); i++) {
        //     cout << "----- from " << airports[i] << endl;
        //     for (int j = 0; j < graph[i].size(); j++) {
        //         cout << airports[graph[i][j]] << " ";
        //     }
        //     cout << endl;
        // }

        auto path = vector<int>(tickets.size() + 1, -1);
        path[0] = map["JFK"],
        dfs(map["JFK"], path, 1);

        return result;
    }
};