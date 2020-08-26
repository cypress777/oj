class Solution {
public:
    vector<vector<int>> adj_list;
    vector<bool> is_cycle_unit;
    vector<bool> checked;
    
    bool isCycleUnit(int id, vector<bool> visited, vector<bool>& stack) {
        if (checked[id]) return is_cycle_unit[id];
        
        if (!visited[id]) {
            visited[id] = true;
            stack[id] = true;
            
            for (int i = 0; i < adj_list[id].size(); i++) {
                int adj_id = adj_list[id][i];
                
                if (!visited[adj_id] && isCycleUnit(adj_id, visited, stack)) return true;
                else if (stack[adj_id]) return true;
            }
        }
        
        checked[id] = true;
        is_cycle_unit[id] = false;
        stack[id] = false;
        return false;
    }
     
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj_list = vector<vector<int>>(numCourses, vector<int>{});
        is_cycle_unit = vector<bool>(numCourses, true);
        checked = vector<bool>(numCourses, false);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int pre_course = prerequisites[i][1];
            
            adj_list[course].push_back(pre_course);
        }
        
        for (int i = 0; i < numCourses; i++) {
            vector<bool> visited(numCourses, false);
            vector<bool> stack(numCourses, false);
            
            if (checked[i] && is_cycle_unit[i]) return false;
            else if (isCycleUnit(i, visited, stack)) return false;
        }
        return true;
    }
};
