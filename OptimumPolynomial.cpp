#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std;

vector<float> LagrangePolynomial(int n, vector<float> xVals, vector<float> yVals);
int f(n);

int main()
{
    for (int i = 1; i < 12; i++)
    {
        for (int j = 1; j < i+1; j++)
        {

        }
    }
}

vector<float> LagrangePolynomial(int n, vector<float> xVals, vector<float> yVals)
{
    assert(xVals.size() == yVals.size());

    int k = yVals.size();

    int res = 0;
    for (int i = 0; i < k; i++)
    {
        int L = 1;
        for (int j = 0; j < k; j++)
        {
            if (j != i)
            {
                L *= (n - x[j])/(x[i] - x[j])
            }
        }
        res += yVals[i]*L;
    }

    return res;
}

int f(n)
{
    return (pow(-1*n, 10) - 1)/(-1*n - 1);
}