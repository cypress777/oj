//
// Created by cypress on 2018/8/26.
//
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "LargeNumHelper.hpp"

using namespace std;

int main()
{
    ifstream fnums;
    fnums.open("../50digit.txt", ios::in);

    vector<vector<char>> nums(100, vector<char>(12, 0));

    string num;
    int i = 0;
    while (getline(fnums, num))
    {
        for (int j = 0; j < 12; j++)
            nums[i][12 - j - 1] = num.c_str()[j];
        i++;
    }

    vector<char> res = vector<char>();
    for (int k = 0; k < 100; k++)
    {
        res = largeNumSum(nums[k], res);
        for (int i = 0; i < 14; i++)
            cout << res[i];
        cout << endl;
    }

    for (int k = 0; k < 14; k++)
        cout << res[k];
    cout << endl;
}

