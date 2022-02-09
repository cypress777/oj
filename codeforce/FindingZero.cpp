#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

int query(const vector<int>& ids) {
    cout << "? " << ids[0] + 1 << " " << ids[1] + 1 << " " << ids[2] + 1 << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int init(vector<int>& res) {
    int diff_0 = query({1, 2, 3});
    int diff_1 = query({0, 2, 3});
    int diff_2 = query({0, 1, 3});
    int diff_3 = query({0, 1, 2});
    int max_diff = max(diff_0, max(diff_1, max(diff_2, diff_3)));
    if (diff_2 == max_diff && diff_3 == max_diff) res = {0, 1, 2};
    if (diff_0 == max_diff && diff_3 == max_diff) res = {1, 2, 0};
    if (diff_1 == max_diff && diff_3 == max_diff) res = {0, 2, 1};
    if (diff_1 == max_diff && diff_2 == max_diff) res = {0, 3, 1};
    if (diff_0 == max_diff && diff_2 == max_diff) res = {1, 3, 0};
    if (diff_0 == max_diff && diff_1 == max_diff) res = {2, 3, 0};

    return max_diff;
}

void ask(const vector<int>& ids) {
    cout << "! " << ids[0] + 1 << " " << ids[1] + 1 << endl;
    cout.flush();
}

void calc() {
    int n;
    cin >> n;

    vector<int> ids = {-1, -1, -1};
    int max_diff = init(ids);
    // cout << "----- " << ids[0] << " " << ids[1] << " " << ids[2] << " " << max_diff << endl;

    for (int i = 4; i < n; i++) {
        int diff_0 = query({i, ids[1], ids[2]});
        int diff_1 = query({ids[0], i, ids[2]});
        if (diff_0 > max_diff || diff_1 > max_diff) {
            if (diff_0 > diff_1) {
                max_diff = diff_0;
                ids[0] = i;
            } else {
                max_diff = diff_1;
                ids[1] = i;
            }
        }
        // cout << "----- " << ids[0] << " " << ids[1] << " " << ids[2] << " " << max_diff << endl;
    }

    ask(ids);
}

int main() {
    // freopen("in.txt", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        calc();
    }

    return 0;
}