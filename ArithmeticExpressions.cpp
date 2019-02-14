#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int MM = 10000000;
double mm = 10e-12;

void cout_vec(const vector<int> &vec) {
    for (auto n : vec) cout << n << " ";
    cout << endl;
}

double cal(double a, double b, double op) {
    if (abs(a) >= MM || abs(b) >= MM) return MM;
    if (op == 0) {
        return a + b;
    } else if (op == 1) {
        return a - b;
    } else if (op == 2) {
        return a * b;
    } else if (op == 3) {
        if (abs(b) < mm) {
            return MM;
        } else {
            return a / b;
        }
    } else {
        return MM;
    }
}

bool next_permutation(vector<int> &nums) {
    int r;
    for (r = nums.size() - 1; r > 0; r--) if (nums[r] > nums[r - 1]) break;
    if (r == 0) return false;  // already last permutation

    sort(nums.begin() + r, nums.end());

    for (int i = r; i < nums.size(); i++) {
        if (nums[i] > nums[r - 1]) {
            int tmp = nums[i];
            nums[i] = nums[r - 1];
            nums[r - 1] = tmp;
            break;
        }
    }
    return true;
}

int main() {
    int max_len = 0;
    vector<int> max_vec;

    for (int a = 1; a < 10; a++) for (int b = a + 1; b < 10; b++) for (int c = b + 1; c < 10; c++) for (int d = c + 1; d < 10; d++) {
        vector<int> nums = {a, b, c, d};
        vector<int> results(9 * 8 * 7 * 6 + 1, 0);
        while (true) {
            for (int op1 = 0; op1 < 4; op1++) for (int op2 = 0; op2 < 4; op2++) for (int op3 = 0; op3 < 4; op3++) {
                double result;

                // a op1 b op2 c op3 d
                result = cal(cal(cal(nums[0], nums[1], op1), nums[2], op2), nums[3], op3);
                if (result > 0 && result < MM && abs(result - int(result)) < mm) results[int(result)] += 1;

                // a op1 (b op2 c) op3 d
                result = cal(cal(nums[0], cal(nums[1], nums[2], op2), op1), nums[3], op3);
                if (result > 0 && result < MM && abs(result - int(result)) < mm) results[int(result)] += 1;

                // a op1 b op2 (c op3 d)
                result = cal(cal(nums[0], nums[1], op1), cal(nums[2], nums[3], op3), op2);
                if (result > 0 && result < MM && abs(result - int(result)) < mm) results[int(result)] += 1;

                // a op1 (b op2 c op3 d)
                result = cal(nums[0], cal(cal(nums[1], nums[2], op2), nums[3], op3), op1);
                if (result > 0 && result < MM && abs(result - int(result)) < mm) results[int(result)] += 1;

                // a op1 (b op2 (c op3 d))
                result = cal(nums[0], cal(nums[1], cal(nums[2], nums[3], op3), op2), op1);
                if (result > 0 && result < MM && abs(result - int(result)) < mm) results[int(result)] += 1;
            }

            if (!next_permutation(nums)) break;
        }

        int len = 0;
        for (int i = 1; i < results.size(); i++)  {
            if (results[i] < 1) break;
            len++;
        }

        if (len > max_len) {
            max_len = len;
            max_vec = vector<int>(nums);
        }
    }

    cout << max_len << endl;
    cout_vec(max_vec);

    return 0;
}