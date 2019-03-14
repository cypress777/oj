//
// Created by cypress on 2018/8/19.
//
#include <iostream>
#include "utils.hpp"

using namespace std;

int main()
{
    long sum1 = 0;
    for (int i = 0; i < 500000; i++)
    {
        if (isPrime(i))
        {
            sum1 += i;
            cout << i << " " << endl;
        }
    }

    long sum2 = 0;
    for (int i = 500000; i < 1000000; i++)
    {
        if (isPrime(i))
        {
            sum2 += i;
            cout << i << " " << endl;
        }
    }

    long sum3 = 0;
    for (int i = 1000000; i < 1500000; i++)
    {
        if (isPrime(i))
        {
            sum3 += i;
            cout << i << " " << endl;
        }
    }

    long sum4 = 0;
    for (int i = 1500000; i < 2000000; i++)
    {
        if (isPrime(i))
        {
            sum4 += i;
            cout << i << " " << endl;
        }
    }
    cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4;
}
