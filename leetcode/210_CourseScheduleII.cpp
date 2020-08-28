class Solution {
public:
    int N;
    vector<vector<int>> orders;
    vector<int> in_degrees;
    int edges;
    
    vector<int> get_path() {
        vector<int> path;
        
        vector<int> queue;
        int cur = 0;
        int del_edges = 0;
        
        for (int i = 0; i < N; i++) {
            if (in_degrees[i] == 0) {
                queue.push_back(i);
            }
        }
        
        while(cur < queue.size()) {
            int node = queue[cur];
            cur++;
            path.push_back(node);
            
            for (int i = 0; i < orders[node].size(); i++) {
                int next_node = orders[node][i];
                in_degrees[next_node]--;
                
                if (in_degrees[next_node] == 0) queue.push_back(next_node);
                
                del_edges++;
            }
        }
        
        if (del_edges < edges) return vector<int>{};
        
        return path;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        N = numCourses;
        orders = vector<vector<int>>(N, vector<int>{});
        in_degrees = vector<int>(N, 0);
        edges = prerequisites.size();
        
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int pre_course = prerequisites[i][1];
            
            orders[pre_course].push_back(course);
            in_degrees[course]++;
        }
        
        return get_path();
    }
};
