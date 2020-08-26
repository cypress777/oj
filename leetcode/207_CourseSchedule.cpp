class Solution {
public:
    vector<vector<int>> adj_list;
    vector<bool> is_cycle_unit;
    vector<bool> checked;
    
    bool isCycleUnit(int id, vector<bool>& stack) {
        if (checked[id]) return is_cycle_unit[id];
        
        if (stack[id]) {
            checked[id] = true;
            is_cycle_unit[id] = true;
            return true;
        }
        
        if (!stack[id]) {
            stack[id] = true;
            
            for (int i = 0; i < adj_list[id].size(); i++) {
                int adj_id = adj_list[id][i];
                
                if (isCycleUnit(adj_id, stack)) {
                    checked[id] = true;
                    is_cycle_unit[id] = true;
                    return true;
                }
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
            vector<bool> stack(numCourses, false);
            
            if (isCycleUnit(i, stack)) return false;
        }
        return true;
    }
};
