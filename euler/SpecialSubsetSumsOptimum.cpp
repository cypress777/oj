#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> up_A = {20, 31, 38, 39, 40, 42, 45};
int up_SA = 0;
vector<int> pre_A = {11, 18, 19, 20, 22, 25};
int bot_SA = 0;

bool jointed(const vector<int> a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) if (a[i] == b[j]) return true;
    return false;
} 

void gen_sub_sets(const vector<int> &A, vector<vector<int>> &subs) {
    for (int i = 0; i < A.size() - 1; i++) for (int j  = i + 1; j < A.size(); j++) {
        vector<int> sub2 = {A[i], A[j]};
        subs.emplace_back(sub2);

        if (j < A.size() - 1) for (int k = j + 1; k < A.size(); k++) {
            vector<int> sub3 = {A[i], A[j], A[k]};
            subs.emplace_back(sub3);
        }
    }
}

int sum_set(const vector<int> &a) {
    int s = 0;
    for (int n : a) s += n;
    return s;
}

bool is_valid(const vector<int> &A) {
    if (A.size() < 3) return true;
    if (A[0] + A[1] <= A[A.size() - 1]) return false;
    if (A.size() > 3) if (A[0] + A[1] + A[2] <= A[A.size() - 2] + A[A.size() - 1]) return false;
    if (A.size() > 4) if (A[0] + A[1] + A[2] + A[3] <= A[A.size() - 3] + A[A.size() - 2] + A[A.size() - 1]) return false;

    vector<vector<int>> subs{};
    gen_sub_sets(A, subs);
    for (int i = 0; i < subs.size() - 1; i++) for (int j = i + 1; j < subs.size(); j++) {
        if (jointed(subs[i], subs[j])) continue;

        int si = sum_set(subs[i]);
        int sj = sum_set(subs[j]);
        int szi = subs[i].size();
        int szj = subs[j].size();
        if (szi == szj && si == sj || szi > szj && si <= szj || szi < szj && szi >= szj) return false;
    }

    return true;
}

bool gen(int SA, const vector<int> &A) {
    if (!is_valid(A)) return false;

    int low = A.empty() ? 1 : A[A.size() - 1] + 1;

    int sum_A = sum_set(A);

    if (A.size() == 7) {
        if (sum_A == SA) {
            cout << "sa: " << SA << endl;
            for (int n : A) cout << n << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    int high = SA - sum_A;
    if (high < low) return false;
    if (A.size() == 6) low = high;

    for (int i = low; i <= high; i++) {
        vector<int> a = A;
        a.emplace_back(i);
        if (gen(SA, a)) return true;
    }
    return false;
}

int main() {
    for (int n : up_A) up_SA += n;
    for (int n : pre_A) bot_SA += n;

    for (int i = bot_SA; i <= up_SA; i++) {
        vector<int> A{};
        if (gen(i, A)) return 0;
    }

    return 0;
}