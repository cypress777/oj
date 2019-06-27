#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../src/math_utils.hpp"

using namespace std;

long long MM = 100000L;
vector<long long> ptab;
vector<unordered_set<int>> add_loop;

bool able_to_add(long long len) {
//    cout << len << " ";
    while (len % 5 == 0) len /= 5;
    while (len % 2 == 0) len /= 2;
//    cout << len << endl;
    return len == 1;
}

bool is_factor(long long p) {
    unordered_map<long long, long long> seq;

    long long rem = 1, l = 1, loop_len = 0;
    seq[1] = 1;

    while (true) {
        rem = (rem * 10 + 1) % p;
        l++;

        if (seq.find(rem) == seq.end()) {
            seq[rem] = l;
        } else {
            loop_len = l - seq[rem];
            break;
        }
    }

    if (seq.find(0) != seq.end()) {
//        cout << "--- " << p << " ";
        return able_to_add(loop_len);
    }
    return false;
}


int main() {
    gen_prime_tab(MM, ptab);
    cout << ptab.size() << endl;

    long long res = 0;
    int cnt = 0;

    for (int p : ptab) {
        if (!is_factor(p)) {
            res += p;
        } else {
            cnt++;
            cout << cnt << " " << p << endl;
        }
    }

    cout << res << endl;

    return 0;
}

