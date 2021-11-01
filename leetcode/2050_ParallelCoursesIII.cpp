class Solution {
public:
    struct Schedule {
        int id;
        int finish;
        
        Schedule(int id, int finish): id(id), finish(finish) {}
    };
    
    struct CompareHeight {
        bool operator()(Schedule const& s1, Schedule const& s2)
        {
            return s1.finish > s2.finish;
        }
    };
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        auto graph = vector<vector<int>>(n, vector<int>{});
        auto in_degree = vector<int>(n, 0);
        
        for (auto relation : relations) {
            int pre = relation[0] - 1;
            int next = relation[1] - 1;
            graph[pre].push_back(next);
            in_degree[next]++;
        }
        
        priority_queue<Schedule, vector<Schedule>, CompareHeight> pq;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                pq.push(Schedule(i, time[i]));
            }
        }
        
        int last_time = 0;
        while (!pq.empty()) {
            auto cur_schedule = pq.top();
            pq.pop();
            
            last_time = cur_schedule.finish;
            
            for (int next : graph[cur_schedule.id]) {
                in_degree[next]--;
                if (in_degree[next] == 0) {
                    pq.push(Schedule({ next, cur_schedule.finish + time[next] }));
                }
            }
        }
        return last_time;
    }
};