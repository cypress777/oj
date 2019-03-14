#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    for (int a = 9; a > 0; a--)
    {
        for (int b = 9; b > -1; b--)
        {
            for (int c = 7; c > -1; c--)
            {
                int num = a * 100000 + b * 10000 + c * 1000 + c * 100 + b * 10 + a;
                for (int div = 100; div < (int)sqrt(num) + 1; div++)
                {
                    if (num % div == 0 && num / div < 1000 && num / div > 100)
                    {
                        cout << num << endl;
                        cout << div << endl;
                        return 1;
                    }
                }
            }
        }
    }
    for (int a = 9; a > 0; a--)
    {
        for (int b = 9; b > -1; b--)
        {
            for (int c = 9; c > -1; c--)
            {
                int num = a * 10000 + b * 1000 + c * 100 + b * 10 + a;
                for (int div = 100; div < (int)sqrt(num) + 1; div++)
                {
                    if (num % div == 0 && num / div < 1000 && num / div > 100)
                    {
                        cout << num << endl;
                        cout << div << endl;
                        return 1;
                    }
                }
            }
        }
    }
}