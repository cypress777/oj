#include <iostream>
#include <vector>

using namespace std;

long long cal(int c, int doors) {
    vector<long long> M(doors + 1, 0);
    M[1] = 1;

    for (int i = 2; i <= doors; i++) {
        long long hand = min(M[i - 1] + 1, (long long)c);
        long long box = M[i - 1] - (hand - 1);
        long long box_cost = box / (c - 2) * c + (box % (c - 2) > 0 ? box % (c - 2) + 2 : 0);

//        cout << i << " " << hand << " " << box << " " << box_cost << endl;

        M[i] = hand + box_cost;
    }

    return M[doors];
}

int main() {
    int rooms = 30;
    int c_min = 3;
    int c_max = 40;

    int doors = 1 + rooms;

    long long tot = 0;
    for (int c = c_min; c <= c_max; c++) {
        tot += cal(c, doors);
    }

    cout << tot << endl;

    return 0;
}

