#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool in_set(const vector<int> &set, int n) {
    int pos = lower_bound(set.begin(), set.end(), n) - set.begin();
    return (pos < set.size() && set[pos] == n);
}

int calc(int n, vector<int> set, int step, int step_limit) {
    sort(set.begin(), set.end());
    if (in_set(set, n)) return step;

    if (step + 1 >= step_limit) return step_limit;

    int result = step_limit;
    for (int i = 0; i < set.size(); i++) {
        for (int j = i; j < set.size(); j++) {
            int new_v = set[i] + set[j];

            if (new_v == n) return step + 1;

            if (in_set(set, new_v)) continue;

            vector<int> new_set = set;
            new_set.push_back(new_v);

            result = calc(n, new_set, step + 1, result);
            if (result < step_limit) return result;
        }
    }
    return result;
}

int main() {
    int mm = 200;
    int tot = 0;
    vector<int> results(mm + 1, -1);
    results[1] = 0;

    for (int i = 2; i <= mm; i++) {
        int limit = results[i / 2] + 2;

        results[i] = calc(i, {1}, 0, limit);

        cout << i << " " << limit << " " << results[i] << endl;
        tot += results[i];
    }

    cout << tot << endl;

    return 0;
}

