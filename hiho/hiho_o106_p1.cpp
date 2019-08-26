#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    int tot_pending = 0, tot_canceled = 0, tot_paid = 0;

    unordered_map<int, int> pending;

    for (int i = 0; i < N; i++) {
        string type;
        cin >> type;

        int id, amount;
        cin >> id;

        if (type == "CREATE") {
            cin >> amount;
            if (pending.find(id) == pending.end()) {
                pending[id] = amount;
            } else {
                pending[id] += amount;
            }
        } else if (type == "CANCEL") {
            tot_canceled += pending[id];
            pending.erase(id);
        } else if (type == "PAY") {
            tot_paid += pending[id];
            pending.erase(id);
        } else {
            cout << type << endl;
        }
    }

    for (auto v : pending) {
        tot_pending += v.second;
    }

    cout << tot_paid << " " << tot_canceled << " " << tot_pending << endl;

    return 0;
}

