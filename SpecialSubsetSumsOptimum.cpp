#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> up_A = {20, 31, 38, 39, 40, 42, 45};
int up_SA = 0;
vector<int> pre_A = {11, 18, 19, 20, 22, 25};
int bot_SA = 0;

bool is_valid(const vector<int> &A) {
    if (A.size() < 3) return true;
    if (A[0] + A[1] <= A[A.size() - 1]) return false;
    if (A.size() > 3) if (A[0] + A[1] + A[2] <= A[A.size() - 2] + A[A.size() - 1]) return false;
    if (A.size() > 4) if (A[0] + A[1] + A[2] + A[3] <= A[A.size() - 3] + A[A.size() - 2] + A[A.size() - 1]) return false;

    return true;
}

bool gen(int SA, const vector<int> &A) {
    // cout << "--- " << SA << " " << A.size() << endl;

    if (!is_valid(A)) return false;

    int low = A.empty() ? 1 : A[A.size() - 1] + 1;

    int sum_A = 0;
    if (!A.empty()) for (int n : A) sum_A += n;

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
    if (high <= low) return false;

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
    cout << up_SA << endl;
    return 0;
}