#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int MM = 16;
int status_cnt;
int N;

int to_int(bitset<N> code) {
    return static_cast<int>)(mybit.to_ulong());
}

bitset<N> get_next(const bitset<N> &cur_code) {

}

int main() {
    int n, m;
    cin >> n >> m;

    status_cnt = 2 ** n;
    N = n + 1;

    int a, b, c;
    cin >> a >> b >> c;

    vector<unordered_set<int>> attack(n, unordered_set<int>()), restrict(n, unordered_set<int>());
    vector<bool> navigate(n);

    int x, y;
    for (int i = 0; i < a; i++) {
        cin >> x >> y;
        attack[x].insert(y);
    }

    for (int i = 0; i < b; i++) {
        cin >> x >> y;
        restrict[x].insert(y);
    }

    for (int i = 0; i < c; i++) {
        cin >> x;
        navigate[x] = true;
    }

    bitset<N> start_code;
    bitset<N> end_code.set(1);

    vector<int> steps(status_cnt, -1);
    vector<int> vst(status_cnt, -1);

    vector<bitset<N>> que;

    steps[0] = 0;
    vst[0] = 1;
    que.push_back(start_code);
    int que_cursor = 0;

    while (que.size() > que_cursor) {
        bitset<N> cur_code = que[que_cursor];
        que_cursor++;

        if (cur_code == end_code) {
            cout << steps[to_int(cur_code)] << endl;
            return 0;
        }

        vector<bitset<N>> next_codes = get_next(cur_code);

        for (auto next_code : next_codes) {
            if (vst[next_code] == 1) continue;

            vst[to_int(next_code)] = 1;

            steps[to_int(next_code)] = steps[to_int(cur_code)] + 1;

            que.push_back(next_code);
        }
    }

    return 0;
}

