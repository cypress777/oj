//
// Created by cypress on 2018/8/19.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b, c;
    for (int i = 1; i < 1000; i++)
    {
        a = i;
        for (int j = 1; j < 1000 - i; j++)
        {
            b = j;
            int s = (int)sqrt(a*a + b*b);
            if (s*s == (a*a + b*b)){
                c = s;
                if (a + b + c == 1000)
                {
                    cout << a << ' ' << b << ' ' << c << endl;
                    cout << a*b*c << endl;
                    return 1;
                }
            }
        }
    }
}