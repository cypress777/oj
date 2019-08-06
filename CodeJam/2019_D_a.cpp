#include <iostream>
#include <set>

using namespace std;

bool is_even(int v) {
    int cnt = 0;

    while (v > 0) {
        if (v % 2 == 1) cnt++;
        v /= 2;
    }

    return cnt % 2 == 0;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, Q;
        cin >> N >> Q;

        set<int> ids;
        int array_size = 0;
        for (int j = 0; j < N; j++) {
            int n;
            cin >> n;

            array_size++;

            if (!is_even(n)) {
                ids.insert(j);
            }
        }

        cout << "Case #" << i + 1 << ":";

        for (int j = 0; j < Q; j++) {
            int p, v;
            cin >> p >> v;

            if (!is_even(v)) {
                ids.insert(p);
            } else {
                ids.erase(p);
            }

            int len;
            int size = ids.size();

            if (size % 2 == 0) {
                len = array_size;
            } else {
                len = array_size - min(*ids.begin() + 1, array_size - *ids.rbegin());
            }

            cout << " " << len;
        }

        cout << endl;
    }

    return 0;
}