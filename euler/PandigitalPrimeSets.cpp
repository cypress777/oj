#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include "../src/math_utils.hpp"
#include <chrono>

using namespace std;

vector<int> prime_tab;
unordered_set<int> prime_showed;
int MM ;
int LEN = 9;
int NN, tot;

bool is_valid(int n) {
    return !(prime_showed.find(n) == prime_showed.end());
}

void split(const vector<int> &list) {
    for (int i = 0; i <= NN; i++) {
        int flg = i;
        int cur = list[0];
        int last = 0;

        bool valid = true;
        vector<int> res;
        for (int j = 1; j < LEN; j++) {
            if (flg % 2 == 0) {
                cur = cur * 10 + list[j];
            } else {
                valid = (is_valid(cur) && cur > last);
                if (!valid) break;

                res.push_back(cur);
                last = cur;
                cur = list[j];
            }
            flg /= 2;
        }

        if (valid && is_valid(cur) && cur > last) {
            res.push_back(cur);

//            cout << "res: ";
//            for (int r : res) cout << r << " ";
//            cout << endl;

            tot++;
        }
    }
}

void cal(const vector<int> &list) {
    if (list.size() == LEN) {
        split(list);
    } else {
        for (int i = 1; i <= LEN; i++) {
            int used = false;
            for (int l : list) {
                if (i == l) {
                    used = true;
                    break;
                }
            }

            if (used) continue;

            auto new_list = list;
            new_list.push_back(i);
            cal(new_list);
        }
    }
}

int main () {
    MM = pow(10, LEN) - 1;

    cout << "111" << endl;
    gen_prime_tab(MM, prime_tab);

    cout << "111" << endl;
    for (int p : prime_tab) prime_showed.insert(p);

    cout << "111" << endl;
    NN = 1;
    for (int i = 0; i < LEN - 1; i++, NN *= 2);
    NN -= 1;

    tot = 0;
    cal({});

    cout << tot << endl;

    return 0;
}

