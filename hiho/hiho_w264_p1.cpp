#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<double> probs;
    for (int i = 0; i < N; i++) {
        double p;
        cin >> p;
        probs.push_back(p);
    }

    vector<vector<double>> res(N, vector<double>(M + 10, 0));
    res[0][0] = 1 - probs[0];
    res[0][1] = probs[0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            res[i][j] = res[i - 1][j] * (1 - probs[i]);
            if (j > 0) res[i][j] += res[i - 1][j - 1] * (probs[i]);
        }
    }

    cout << res[N - 1][M] << endl;

    return 0;
}
