#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int MM = 1000000;

    int N;
    cin >> N;

    vector<int> a(N, 0);
    vector<int> count(MM + 1, 0);

    int max_len = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        count[a[i]]++;
        if (count[a[i]] > max_len) max_len = count[a[i]];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            int cur = a[i];
            int diff = a[j] - a[i];
            if (diff == 0 || cur - diff > 0 && count[cur - diff] > 0) continue;

            int len = 0;
            while (cur <= MM && count[cur] > 0) {
                len++;
                cur += diff;
            }

            if (len > max_len) max_len = len;
        }
    }

    cout << max_len << endl;
}