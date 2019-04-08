#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N = 1000000000;
//    int N = 2;

    vector<int> times = vector<int>(1000, 0);
    times[0] = 1;
    int size = 1;

    while (size < N) {
        for (int i = 0; i < times.size(); i++) {
            if (times[i] > 0) {
                int k = min(times[i], N - size);
                times[i + 1] += k;
                times[i + 4] += k;
                times[i] -= k;
                size += k;
                break;
            }
        }
    }

    long long total_val = 0;
    for (int i = 0; i < times.size(); i++) total_val += (long long)i * times[i];
    cout << total_val << endl;

    return 0;
}
