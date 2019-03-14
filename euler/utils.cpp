//
// Created by cypress on 2018/8/17.
//
#include "utils.hpp"

bool isPrime(long N)
{
    if (N == 1 || N == 4 || N ==6)
        return false;
    if (N == 2 || N == 3 || N == 5 || N == 7)
        return true;
    for (auto i = 2; i < N; i++)
    {
        if (N != i && N%i == 0) return false;
    }
    return true;
}