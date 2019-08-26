#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int MM = 1000000;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> number_count;

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;

        if (number_count.find(v) == number_count.end()) {
            number_count[v] = 1;
        } else {
            number_count[v]++;
        }
    }

    vector<int> count;
    for (auto n : number_count) {
        count.push_back(n.second);
    }

    sort(count.begin(), count.end());

    vector<int> slot;
    for (int i = 0; i < count.size(); i++) {
        if (i > 0 && count[i] == count[i - 1]) continue;

        for (int j = i > 0 ? count[i - 1] + 1 : 1; j < count[i]; j++) {
            slot.push_back(j);
        }
    }

    int slot_cur = slot.size() - 1;
    int step = 0;

    for (int i = count.size() - 2; i >= 0; i--) {
        if (count[i] == count[i + 1]) {
            while(slot_cur >= 0 && slot[slot_cur] >= count[i]) {
                slot_cur--;
            }

            if (slot_cur < 0) {
                step += count[i];
            } else {
                step += count[i] - slot[slot_cur];
                slot_cur--;
            }
        }
    }

    cout << step << endl;

    return 0;
}
