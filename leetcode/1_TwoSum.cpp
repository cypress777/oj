class Solution_fin {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); i++) {
            index[nums[i]] = i;
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (index.find(target - nums[i]) != index.end() &&
                index[target - nums[i]] != i) {
                res.push_back(i);
                res.push_back(index[target - nums[i]]);

                break;
            }
        }
        return res;
    }
};

struct Num {
    int val;
    int idx;

    Num(int v, int id) : val(v), idx(id) {}
    Num() : val(0), idx(0) {}
};

class Solution {
public:
    static bool comp(Num a, Num b) {
        return a.val < b.val;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        id_num = vector<Num>(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            id_num[i].val = nums[i];
            id_num[i].idx = i;
        }

        sort(id_num.begin(), id_num.end(), comp);

        int lp = 0, rp = id_num.size() - 1;

        vector<int> res;
        while (lp < rp) {
            int cur = id_num[lp].val + id_num[rp].val;

            if (cur == target) {
                res.push_back(id_num[lp].idx);
                res.push_back(id_num[rp].idx);
                sort(res.begin(), res.end());
                break;
            } else if (cur < target) {
                lp++;
            } else {
                rp--;
            }
        }

        return res;
    }

    vector<Num> id_num;
};
