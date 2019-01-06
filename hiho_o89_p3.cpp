#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) return a[2] < b[2];
    return a[0] < b[0];
}

int main() {
    int N;
    cin >> N;
    cout << N << endl;

    vector<vector<int>> intervals(N, vector<int>(4, -1));
    vector<vector<int>> res{};

    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        int start = 0;
        int s1_include = 0;
        if (s1[0] == '[') s1_include = 1;
        int j = 1;
        while (s1[j] != ',') {
            start *= 10;
            start += s1[j] - '0';
            j++;
        }

        int end = 0;
        int s2_include = 0;
        j = 0;
        while (s2[j] != ')' && s2[j] != ']') {
            end *= 10;
            end += s2[j] - '0';
            j++;
        }
        if (s2[j] == ']') s2_include = 1;

        intervals[i][0] = start;
        intervals[i][1] = end;
        intervals[i][2] = s1_include;
        intervals[i][3] = s2_include;
    }

    sort(intervals.begin(), intervals.end(), comp);
    for (int i = 0; i < N; i++) {
        cout << i << " " << intervals[i][0] << " " << intervals[i][1] << " " << intervals[i][2] << " " << intervals[i][3] << endl;
    }

    int r = intervals[0][0], f = intervals[0][1], r_include = intervals[i][2], f_include = intervals[i][3];
    for (int i = 1; i < N; i++) {
        if (intervals[i][0] > f || intervals[i][0] == f && intervals[i][2] + f_include == 0 || i == N - 1) {
            vector<int> inter = {r, f, r_include, f_include};
            res.push_back(inter);
            r = intervals[i][0];
            f = intervals[i][1];
            r_include = intervals[i][2];
            f_include = intervals[i][3];
        } else {
            f = max(f, intervals[i][1]);
            f_include = intervals[i][1] 
        }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << '[' << res[i][0] << ", " << res[i][1] << ']' << endl;
    }

    return 0;
}