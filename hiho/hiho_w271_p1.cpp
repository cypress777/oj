#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> chain(N + 1);
    vector<int> len(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        cin >> chain[i];
    }

    vector<int> vst(N + 1, -1);

    int k = 1;
    int max_size = 1;
    while (k <= N) {
        if (vst[k] != -1) {
            k++;
            continue;
        }

        vst[k] = 1;
        int p = chain[k];
        unordered_set<int> group;
        while (p <= N && p >= 1) {
            if (group.find(p) != group.end()) {
                max_size = max(max_size, int(group.size()));
                group.clear();
                break;
            }

            vst[p] = 1;
            group.insert(p);
            p = chain[p];
        }

        k++;
    }

    cout << max_size << endl;

    return 0;
}

