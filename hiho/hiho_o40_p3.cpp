#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
        }
    }

//    cout << "----" << endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << map[i][j] << " ";
//        }
//        cout << endl;
//    }

    vector<vector<int>> left(n, vector<int>(m, 1));
    vector<vector<int>> up(n, vector<int>(m, 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) {
                if (map[i][j] != map[i][j - 1]) left[i][j] = left[i][j - 1] + 1;
            }

            if (i > 0) {
                if (map[i][j] != map[i - 1][j]) up[i][j] = up[i - 1][j] + 1;
            }
        }
    }

//    cout << "----" << endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << left[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "----" << endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << up[i][j] << " ";
//        }
//        cout << endl;
//    }

    int max_res = 1;
    vector<vector<int>> res(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && j > 0) {
                res[i][j] = min(min(res[i - 1][j - 1] + 1, left[i][j]), up[i][j]);
                max_res = max(max_res, res[i][j]);
            }
        }
    }

    cout << max_res << endl;

    return 0;
}

