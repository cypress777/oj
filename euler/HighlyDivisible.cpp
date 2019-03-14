//
// Created by cypress on 2018/8/19.
//

#include <iostream>
#include <math.h>

using namespace std;

long divNum(long N)
{
    long res = 0;

    long i = 1;
    for (i = 1; i < sqrt(N); i++)
    {
        if (N%i == 0) res += 2;
    }
    if (i*i == N) res--;

    return res;
}

int main() {
    int i = 0;
    long tri = 0;
    int divnum = 0;
    while (divnum <= 500)
    {
        i++;
        tri = (1+i)*i/2;
        divnum = divNum(tri);
    }
    cout << i << endl;
    cout << tri << endl;
    cout << divnum << endl;
}

