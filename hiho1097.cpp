#include <iostream>
#include <vector>

using namespace std;

int n;
int MM = 10001;
vector<vector<int>> A;

int main() {
    cin >> n;

    A = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> P(n, MM);

    int tree = 0;
    int spent = 0;
    while (tree < n) {
        int id = -1;
        int min = MM;
        for (int i = 0; i < n; i++) {
            if (P[i] != 0 && P[i] <= min) {
                min = P[i];
                id = i;
            }
        }
        tree++;
        if (tree > 1) spent += P[id];
        P[id] = 0;

        for (int i = 0; i < n; i++) {
            if (P[i] > A[i][id]) P[i] = A[i][id];
        }
    }

    cout << spent << endl;
    return 0;
}

