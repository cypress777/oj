#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>
#include <iomanip>

using namespace std;

double LagrangePolynomial(int k, int n, vector<double> xVals, vector<double> yVals);
double f(int n);

int main()
{
    vector<double> xVals;
    vector<double> yVals;

    for (int i = 1; i < 11; i++)
    {
        xVals.push_back(i);
        yVals.push_back(f(i));
        cout << xVals[i-1] << " " << yVals[i-1] << endl;
    }

    double res = 0;
    for (int i = 1; i < 11; i++)
    {
       double op =  LagrangePolynomial(i, i+1, xVals, yVals);
       res += op;
       cout << setprecision(15) << yVals[i-1] << " " << op << endl;
    }
    cout << res << endl;
}

double LagrangePolynomial(int k, int n, vector<double> xVals, vector<double> yVals)
{
    assert(xVals.size() == yVals.size());

    double res = 0;
    for (int i = 0; i < k; i++)
    {
        double L = 1;
        for (int j = 0; j < k; j++)
        {
            if (j != i)
            {
                L *= (n - xVals[j])/(xVals[i] - xVals[j]);
            }
        }
        res += yVals[i]*L;
    }

    return res;
}

double f(int n)
{
    return (1 + pow(n, 11))/(1 + n);
}
