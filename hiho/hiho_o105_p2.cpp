#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string number;
    cin >> number;

    vector<int> max_val(number.size());
    vector<int> max_id(number.size());

    int cur_max = 0;
    int cur_max_id = -1;
    for (int i = number.size() - 1; i >= 0; i--) {
        int v = number[i] - '0';

        if (v > cur_max) {
            cur_max = v;
            cur_max_id = i;
        }

        max_val[i] = cur_max;
        max_id[i] = cur_max_id;
    }

    for (int i = 0; i < number.size() - 1; i++) {
        int n = number[i] - '0';

        if (max_val[i + 1] >= n) {
            int tmp = max_val[i + 1];
            number[max_id[i + 1]] = n + '0';
            number[i] = tmp + '0';
            break;
        }

        if (i == number.size() - 2) {
            char tmp = number[i + 1];
            number[i + 1] = number[i];
            number[i] = tmp;
        }
    }

    cout << number << endl;

    return 0;
}

