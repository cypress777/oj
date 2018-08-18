//
// Created by cypress on 2018/8/15.
//
#include <math.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "utils.hpp"

using namespace std;

void getPrimeDivisor(long num, vector<int>& primeDivisors);

void fgetPrimeDivisor(long num, vector<int>& primeDivisors);

int main()
{
    vector<int> primes;
    vector<int> fprimes;
    time_t t0 = time(NULL);
    getPrimeDivisor(600851475143, primes);
    time_t t1 = time(NULL);
    fgetPrimeDivisor(600851475143, fprimes);
    time_t t2 = time(NULL);

    cout << "method1 time spent: " << t1 - t0 << endl;
    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << endl;
    }

    cout << "method2 time spent: " << t2 - t1 << endl;
    for (int i = 0; i < fprimes.size(); i++)
    {
        cout << fprimes[i] << endl;
    }
}

void fgetPrimeDivisor(long num, vector<int>& primeDivisors)
{
    if (num == 1)
        return;

    for (int i = 2; i < num + 1; i++)
    {
        if (i == num)
        {
            primeDivisors.push_back(num);
            return;
        }
	if (isPrime(i))
        {
            if (num % i == 0)
            {
                primeDivisors.push_back(i);
                fgetPrimeDivisor(num / i, primeDivisors);
                return;
            }
        }
    }
}
void getPrimeDivisor(long num, vector<int>& primeDivisors)
{
    if (isPrime(num))
    {
        primeDivisors.push_back(num);
        return;
    }

    auto N = (long)sqrt(num);
    if (N*N == num && isPrime(N))
    {
        primeDivisors.push_back(N);
        primeDivisors.push_back(N);
        return ;
    }

    for (int i = 2; i < N + 1; i++)
    {
	if (isPrime(i))
        {
            if (num % i == 0)
            {
                primeDivisors.push_back(i);
                getPrimeDivisor(num / i, primeDivisors);
                return;
            }
        }
    }
}