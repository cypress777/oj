//
// Created by cypress on 2018/8/17.
//
#include <iostream>
#include <math.h>

using namespace std;

long GCD(long a, long b)
{
    for (long div = min(a, b); div > 0; div--)
    {
        if (a % div == 0 && b % div == 0) return div;
    }
    return 1;
}

long LCM(long a, long b)
{
    long gcd = GCD(a, b);
    long lcm = a*b / gcd;
    return lcm;
}

int main()
{
    int num = 1;
    for (int i = 1; i < 21; i++)
    {
        num = LCM(i, num);
    }
    cout << num << endl;
    return 1;
}
