#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int L;
    while (scanf("%d", &L) > 0) {
        vector<int> seq(L);
        for (int i = 0; i < L; i++) scanf("%d", &seq[i]);

        vector<int> len(1, seq[0]);

        for (int i = 1; i < seq.size(); i++) {
            int pos = lower_bound(len.begin(), len.end(), seq[i]) - len.begin();
            if (pos == len.size()) len.push_back(seq[i]);
            else len[pos] = seq[i];
        }

        cout << len.size() << endl;
    }

    return 0;
}
