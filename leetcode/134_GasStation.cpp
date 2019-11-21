class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num = cost.size();
        int i = 0;
        while (i < num) {
            int hold = 0, j = 0;
            for (j = 0; j < num; j++) {
                int cur = (i + j) % num;
                hold += gas[cur] - cost[cur];
                if (hold < 0) break;
            }

            if (hold < 0) {
                if ((i + j + 1) % num <= i) break;
                i = (i + j + 1) % num;
            }
            if (hold >= 0) return i;
        }

        return -1;
    }
};
