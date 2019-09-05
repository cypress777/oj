#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int MM = 16;
int status_cnt;
int N;
vector<unordered_set<int>> attack;
vector<unordered_set<int>> restrict;
vector<bool> navigate;

bitset<N> to_bit(int status) {
    bitset<N> code;

    int cnt = 0;
    while (status > 0) {
        if (status % 2 == 1) code.set(cnt);

        status /= 2;
        cnt++;
    }
}

int to_int(bitset<N> code) {
    return static_cast<int>)(code.to_ulong());
}

bool has_navigator(const bitset<N> code, int side) {
    for (int i = 0; i < n; i++) {
        if (code.test[i] == side && navigate[i]) return true;
    }

    return false;
}

bool no_conflict(const bitset<N> code, int side) {
    for (int i = 0; i < n; i++) {
        if (code.test[i] == side) {
            bool no_conflict = true;

            if (!attack[i].empty()) {
                for (auto target : attack[i]) {
                    if (code.test[target] == side) {
                        no_conflict = false;
                        break;
                    }
                }

                if (!no_conflict) {
                    for (auto target : restrict) {
                        if (code.test[target] == side) {
                            no_conflict = true;
                            break;
                        }
                    }
                }
            }

            if (!no_conflict) return false;
        }
    }

    return true;
}

void get_next(const bitset<N> &cur_code, const bitset<N> &boat, int cursor, vector<bitset<N>> &next_codes) {
    if (cursor >= n) return;

    int side = cur_code.test(N - 1);

    if (boat.count() > 0 && boat.count() <= m) {
        bitset<N> next_code = (cur_code ^ boat);

        int next_side = (side ^ 0);
        next_code.set(N - 1) = next_side;

        if (has_navigator(boat, 1), no_conflict(boat, 1) && no_conflict(next_code, side) && no_confict(next_code, next_side)) {
            next_codes.push_back(next_code);
        }

        if (boat.count() == m) return;
    }

    for (int i = cursor; i < n; i++) {
        if (cur_code.test[i] != side) continue;

        auto new_boat = boat;
        new_boat.set(i);

        int new_cursor = i + 1;

        if (new_cursor < n) get_next(cur_code, new_boat, new_cursor, next_codes);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    status_cnt = 2 ** n;
    N = n + 1;

    int a, b, c;
    cin >> a >> b >> c;

    attack = vector<unordered_set<int>>(n, unordered_set<int>());
    restrict = vector<unordered_set<int>>(n, unordered_set<int>());
    navigate = vector<bool>(n);

    int x, y;
    for (int i = 0; i < a; i++) {
        cin >> x >> y;
        attack[x].insert(y);
    }

    for (int i = 0; i < b; i++) {
        cin >> x >> y;
        restrict[y].insert(x);
    }

    for (int i = 0; i < c; i++) {
        cin >> x;
        navigate[x] = true;
    }

    bitset<N> start_code;
    bitset<N> end_code.set(1);

    vector<int> steps(status_cnt * 2, -1);
    vector<int> vst(status_cnt * 2, -1);

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

        vector<bitset<N>> next_codes;
        get_next(cur_code, to_bit(0), 0, next_codes);

        for (auto next_code : next_codes) {
            if (vst[to_int(next_code)] == 1) continue;

            vst[to_int(next_code)] = 1;

            steps[to_int(next_code)] = steps[to_int(cur_code)] + 1;

            que.push_back(next_code);
        }
    }

    return 0;
}

