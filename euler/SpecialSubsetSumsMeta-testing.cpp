#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int SIZE = 12;

void pick(const vector<int> &ids, int n, vector<vector<int>> &subsets) {
    if (n == 0) {
        subsets.emplace_back(ids);
        return;
    }

    int start = ids.empty() ? 0 : ids[ids.size() - 1] + 1;

    for (int i = start; i < SIZE; i++) {
        if (i + n - 1 >= SIZE) break;

        vector<int> nids = ids;
        nids.push_back(i);
        pick(nids, n - 1, subsets);
    }
}

bool need_test(const vector<int> &a, const vector<int> &b) {
    for (int aa : a) for (int bb : b) if (aa == bb) return false;

    for (int i = 1; i < a.size(); i++) {
        if ((b[i] > a[i]) != (b[i - 1] > a[i - 1])) return true;
    }
    return false;
}

int main() {
    int count = 0;

    for (int i = 2; i < 7; i++) {
        vector<vector<int>> subsets{};
        pick({}, i, subsets);
        for (int m = 0; m < subsets.size() - 1; m++) for (int n = m + 1; n < subsets.size(); n++) if (need_test(subsets[m], subsets[n])) count++;
    }

    cout << count << endl;

    return 0;
}