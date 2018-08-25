//
// Created by cypress on 2018/8/24.
//
#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    int sumMax = 295425;
    int sumMin = 42925;

    vector<int> allSum(sumMax-sumMin, 0);
    vector<int> numSet;
    for (int i = 0; i < 100; i++)
    {
        numSet.push_back(pow(i, 2));
    }

    for (int i = 0; i < 50; i++)
    {

    }
}