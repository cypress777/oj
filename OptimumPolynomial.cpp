#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std;

vector<float> LagrangePolynomial(int k, int n, vector<float> xVals, vector<float> yVals);
float f(n);

int main()
{
    vector<float> xVals;
    vector<float> yVals;

    for (int i = 1; i < 11; i++)
    {
        xVals.push_back(i);
        yVals.push_back(f(i));
    }

    int res = 0;
    for (int i = 1; i < 12; i++)
    {
        res += LagrangePolynomial(1, i, xVals, yVals);
    }
    cout << res << endl;
}

vector<float> LagrangePolynomial(int k, int n, vector<float> xVals, vector<float> yVals)
{
    assert(xVals.size() == yVals.size());

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

float f(n)
{
    return (pow(-1*n, 10) - 1)/(-1*n - 1);
}