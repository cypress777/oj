//
// Created by cypress on 2018/9/1.
//
#include <iostream>
#include <unordered_map>
#include <assert.h>

using namespace std;

int getRecurrenceLength(int divisor);

int main() {
    int max_len = 0;
    int max_num = 1;
    for (int i = 1; i < 1000; i++) {
        int len = getRecurrenceLength(i);
        if (len > max_len) {
            max_len = len;
            max_num = i;
        }
    }
    cout << max_num << " : " << max_len << endl;
//    cout << getRecurrenceLength(345) << endl;
}

int getRecurrenceLength(int divisor) {
    assert(divisor != 0);

    unordered_map<int, int> recurList;

    int remainder = 10 % divisor;
    int quotient = 10 / divisor;

    int i = 0;
    while (recurList.find(remainder) == recurList.end()) {
        if (remainder == 0) return 0;

        i += 1;

        recurList.insert({remainder, i});

        quotient = (remainder * 10) / divisor;
        remainder = (remainder * 10) % divisor;
    }

    int len = i - recurList.at(remainder) + 1;
    return len;
}