#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<int> alphebet(26);
long long state0 = 0, state_fin = 0;
int out_base = 12, in_base = 0, mid_base = 4;
int out_size = 12, in_size = 4, mid_size = 8;

long long pow3long(long long n) {
    return (long long)pow(3, n);
}

long long get_out(long long sta) {
    return sta / pow3long(out_base);
}

long long get_mid(long long sta) {
    return sta % pow3long(out_base) / pow3long(mid_base);
}

long long get_in(long long sta) {
    return sta % pow3long(mid_base);
}

long long op0(long long sta) {
    long long out = get_out(sta);
    long long mid = get_mid(sta);
    long long in = get_in(sta);

    long long new_out = out / 3 + out % 3 * pow3long(out_size - 1);
    long long new_mid = mid / 3 + mid % 3 * pow3long(mid_size - 1);
    long long new_in = in / 3 + in % 3 * pow3long(in_size - 1);

    return new_out * pow3long(out_base) + new_mid * pow3long(mid_base) + new_in * pow3long(in_base);
}

long long op1(long long sta) {
    long long out = get_out(sta);
    long long mid = get_mid(sta);
    long long in = get_in(sta);

    long long out_first = out / pow3long(out_size - 1);
    long long new_out = mid / pow3long(mid_size - 1) * pow3long(out_size - 1) + out % pow3long(out_size - 1);
    long long new_mid = in / pow3long(in_size - 1) * pow3long(mid_size - 1) + mid % pow3long(mid_size - 1);
    long long new_in = out_first * pow3long(in_size - 1) + in % pow3long(in_size - 1);

    return new_out * pow3long(out_base) + new_mid * pow3long(mid_base) + new_in * pow3long(in_base);
}

long long op2(long long sta) {
    long long out = get_out(sta);
    long long mid = get_mid(sta);
    long long in = get_in(sta);

    long long new_out = out % pow3long(out_size - 1) * 3 + out / pow3long(out_size - 1);
    long long new_mid = mid % pow3long(mid_size - 1) * 3 + mid / pow3long(mid_size - 1);
    long long new_in = in % pow3long(in_size - 1) * 3  + in / pow3long(in_size - 1);

    return new_out * pow3long(out_base) + new_mid * pow3long(mid_base) + new_in * pow3long(in_base);
}

int main() {
    alphebet['Y' - 'A'] = 0;
    alphebet['R' - 'A'] = 1;
    alphebet['G' - 'A'] = 2;

    char ch;

    state0 = 0;
    state_fin = 0;
    for (int i = 0; i < 12; i++) {
        cin >> ch;
        state0 = state0 * 3 + alphebet[ch - 'A'];
        state_fin = state_fin * 3 + alphebet['G' - 'A'];
    }

    for (int i = 0; i < 8; i++) {
        cin >> ch;
        state0 = state0 * 3 + alphebet[ch - 'A'];
        state_fin = state_fin * 3 + alphebet['R' - 'A'];
    }

    for (int i = 0; i < 4; i++) {
        cin >> ch;
        state0 = state0 * 3 + alphebet[ch - 'A'];
        state_fin = state_fin * 3 + alphebet['Y' - 'A'];
    }

    unordered_set<long long> vst;
    vector<long long> que;
    vector<int> step;
    que.push_back(state0);
    step.push_back(0);
    int f = 0;

    while (que.size() > f) {
        long long cur_state = que[f];
        int cur_step = step[f];
        f++;

//        long long tmp = cur_state;
//        cout << "-------cur state " << tmp << " :"<< endl;
//        while (tmp > 0) {
//            cout << tmp % 3 << " ";
//            tmp /= 3;
//        }
//        cout << endl;

        if (vst.find(cur_state) != vst.end()) continue;
        vst.insert(cur_state);

        if (cur_state == state_fin) {
            cout << cur_step << endl;
            break;
        }

        long long next_state;
        for (int i = 0; i < 3; i++) {
            if (i == 0) next_state = op0(cur_state);
            if (i == 1) next_state = op1(cur_state);
            if (i == 2) next_state = op2(cur_state);

            if (vst.find(next_state) == vst.end()) {
                que.push_back(next_state);
                step.push_back(cur_step + 1);
            }

//            long long tmp = next_state;
//            cout << "next state " << i << " :"<< endl;
//            while (tmp > 0) {
//                cout << tmp % 3 << " ";
//                tmp /= 3;
//            }
//            cout << endl;
        }
    }

    return 0;
}

