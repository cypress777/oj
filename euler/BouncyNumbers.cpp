#include <iostream>
#include <vector>

using namespace std;

bool is_consistant(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }

    int start = 1;
    while (digits[start] == digits[start - 1] && start < digits.size()) start++;
    bool increase = digits[start] > digits[start - 1];

    for (int i = start + 1; i < digits.size(); i++) {
        if (digits[i] == digits[i - 1]) continue;
        if (increase != (digits[i] > digits[i - 1])) {
            return false;
        }
    }

    return true;
}

int main() {
    int bouncy_count = 0;
    int total = 100;

    while ((bouncy_count * 100 / total) < 99) {
        total++;
        if (!is_consistant(total)) {
            bouncy_count++;
//            cout << bouncy_count <<  " " << total << " " << (bouncy_count * 100 / total) << endl;
        }
    }

    cout << bouncy_count << " " << total << endl;

    return 0;
}
