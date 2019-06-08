#include <iostream>
#include <unordered_set>

using namespace std;

int MM = 100000000;
int mm = 10000;

long long sum = 0;
unordered_set<int> list;

bool is_pal(int v) {
    int vv = v;
    int nv = 0;
    while (vv > 0) {
        nv = nv * 10 + vv % 10;
        vv /= 10;
    }
    return v == nv;
}

int main() {
    for (int i = 1; i <= mm; i++) {
        long long val = i * i;
        int next = i + 1;

        while ((val += next * next) < MM) {
            if (is_pal(val)) {
                list.insert(val);
            }
            next++;
        }
    }

    long long res = 0;
    for (auto v : list) {
        res += v;
    }

    cout << res << endl;

    return 0;
}