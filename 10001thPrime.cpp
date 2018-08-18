//
// Created by cypress on 2018/8/17.
//
#include <iostream>
#include "utils.hpp"

using namespace std;

int main()
{
    int i = 0;
    long num = 1;
    while (i < 10001)
    {
        num++;
        if (isPrime(num)) i++;
    }
    cout << num << endl;

    return 1;
}