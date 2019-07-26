#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    int MM = 0;
    unordered_map<int, int> cnt_tab;
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;

        if (cnt_tab.find(v) == cnt_tab.end()) cnt_tab[v] = 0;
        cnt_tab[v]++;

        MM = max(MM, v);
    }

    int tot = 0;
    for (int i = 1; i <= MM; i++) {
        if (cnt_tab.find(i) == cnt_tab.end()) break;

        tot += cnt_tab[i];
    }

    cout << tot << endl;

    return 0;
}

