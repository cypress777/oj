#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <cmath>

using namespace std;

const int MM = 17;
int m, n, N, status_cnt;
vector<unordered_set<int>> attack;
vector<unordered_set<int>> restrict;
vector<bool> navigate;

bitset<MM> to_bit(int status) {
    bitset<MM> code;

    int cnt = 0;
    while (status > 0) {
        if (status % 2 == 1) code.set(cnt);

        status /= 2;
        cnt++;
    }
}

int to_int(bitset<MM> code) {
    return static_cast<int>(code.to_ulong());
}

bool has_navigator(const bitset<MM> code, int side) {
    for (int i = 0; i < n; i++) {
        if (code.test(i) == side && navigate[i]) return true;
    }

    return false;
}

bool no_conflict(const bitset<MM> code, int side) {
    for (int i = 0; i < n; i++) {
        if (code.test(i) == side) {
            bool no_conflict = true;

            if (!attack[i].empty()) {
                for (auto target : attack[i]) {
                    if (code.test(target) == side) {
                        no_conflict = false;
                        break;
                    }
                }

                if (!no_conflict) {
                    for (auto target : restrict[i]) {
                        if (code.test(target) == side) {
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

void get_next(const bitset<MM> &cur_code, const bitset<MM> &boat, int cursor, vector<bitset<MM>> &next_codes) {
    if (cursor >= n) return;

    int side = cur_code.test(N - 1);

    if (boat.count() > 0 && boat.count() <= m) {
        bitset<MM> next_code = (cur_code ^ boat);

        int next_side = (side ^ 0);
        next_code.set(N - 1) = next_side;

        if (has_navigator(boat, 1), no_conflict(boat, 1) && no_conflict(next_code, side) && no_conflict(next_code, next_side)) {
            next_codes.push_back(next_code);
        }

        if (boat.count() == m) return;
    }

    for (int i = cursor; i < n; i++) {
        if (cur_code.test(i) != side) continue;

        auto new_boat = boat;
        new_boat.set(i);

        int new_cursor = i + 1;

        if (new_cursor < n) get_next(cur_code, new_boat, new_cursor, next_codes);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    N = n + 1;
    status_cnt = pow(2, N);

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

    bitset<MM> start_code;
    bitset<MM> end_code;
    end_code.set();

    vector<int> steps(status_cnt, -1);
    vector<int> vst(status_cnt, -1);

    vector<bitset<MM>> que;

    steps[0] = 0;
    vst[0] = 1;
    que.push_back(start_code);
    int que_cursor = 0;

    while (que.size() > que_cursor) {
        bitset<MM> cur_code = que[que_cursor];
        que_cursor++;

        if (cur_code == end_code) {
            cout << steps[to_int(cur_code)] << endl;
            return 0;
        }

        vector<bitset<MM>> next_codes;
        get_next(cur_code, to_bit(0), 0, next_codes);

        cout << "---------" << endl;
        for (auto next_code : next_codes) {
            if (vst[to_int(next_code)] == 1) continue;
            cout << next_code << endl;

            vst[to_int(next_code)] = 1;

            steps[to_int(next_code)] = steps[to_int(cur_code)] + 1;

            que.push_back(next_code);
        }
    }

    cout << -1 << endl;

    return 0;
}

