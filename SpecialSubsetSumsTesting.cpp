#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void pick(const vector<int> &ids, int n, const vector<int> &A, vector<int> &results) {
    if (n == 0) {
        int res = 0;
        for (int id : ids) res += A[id];
        results.push_back(res);
        return;
    }

    int start = ids.empty() ? 0 : ids[ids.size() - 1] + 1;

    for (int i = start; i < A.size(); i++) {
        if (i + n - 1 >= A.size()) break;

        vector<int> nids = ids;
        nids.push_back(i);
        pick(nids, n - 1, A, results);
    }
}

bool is_valid(vector<int> A) {
    sort(A.begin(), A.end());
    for (int i = 1; i < A.size(); i++) if (A[i] == A[i - 1]) return false;
    int max_res = A[A.size() - 1];

    for (int i = 2; i < A.size(); i++) {
        vector<int> result{};
        vector<int> ids{};
        pick(ids, i, A, result);
        
        sort(result.begin(), result.end());
        if (result[0] <= max_res) return false;
        for (int j = 1; j < result.size(); j++) if (result[j] == result[j - 1]) return false;
        max_res = result[result.size() - 1];
    }

    return true;
}

int get_sum(const vector<int> &A) {
    int s = 0;
    for (int n : A) s += n;
    return s;
}

int main() {
    ifstream fin("p105_sets.txt", fstream::in);

    long long sum_all = 0;
    string line;
    while (getline(fin, line)) {
        vector<int> set;
        istringstream iss(line);
        int n;
        while (iss >> n) set.push_back(n);
        if (is_valid(set)) {
            sum_all += get_sum(set);
            cout << line << endl;
        }
    }

    cout << sum_all << endl;
    return 0;
}