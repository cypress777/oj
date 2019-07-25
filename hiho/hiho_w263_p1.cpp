#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vals;

    unordered_map<int, int> cnt_tab;
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;

        vals.push_back(v);

        if (cnt_tab.find(v) == cnt_tab.end()) cnt_tab[v] = 0;
        cnt_tab[v]++;
    }

    unordered_map<int, int> sum_tab;
    for (int i = 0; i < vals.size(); i++) {
        for (int j = i + 1; j < vals.size(); j++) {
            int s = vals[i] + vals[j];

            if (sum_tab.find(s) == sum_tab.end()) sum_tab[s] = 0;
            sum_tab[s]++;
        }
    }

    long long tot = 0;
    for (int i = 0; i < vals.size(); i++) {
        for (int j = i + 1; j < vals.size(); j++) {
            int s = vals[i] + vals[j];

            if (vals[i] == vals[j]) {
                tot += sum_tab[s] - 2 * cnt_tab[vals[i]] + 3;
            } else {
                tot += sum_tab[s] - cnt_tab[vals[i]] - cnt_tab[vals[j]] + 1;
            }
        }
    }

    cout << tot << endl;

    return 0;
}

