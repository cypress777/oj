//
// Created by cypress on 2018/8/25.
//
#include <iostream>
#include <vector>
#include <math.h>
#include "LargeNumHelper.hpp"

int main()
{
    vector<char> c10{'4','2','0','1'};
    vector<char> c100(50, '0');
    for (int i = 0; i < c10.size(); i++)
        c100[i] = c10[i];

    for (int i = 2; i < 11; i++)
    {

        vector<char> tmp;
        tmp = largeNumMult(c10, c100);
        for (int j = 0; j < tmp.size(); j++)
            c100[j] = tmp[j];

        for (int k = 0; k < c100.size(); k++)
            cout << c100[c100.size() - k - 1];
        cout << endl;
    }

    vector<char> c1000(400, '0');
    for (int i = 0; i < c100.size(); i++)
        c1000[i] = c100[i];

    for (int i = 2; i < 11; i++)
    {

        vector<char> tmp;
        tmp = largeNumMult(c100, c1000);
        for (int j = 0; j < tmp.size(); j++)
            c1000[j] = tmp[j];

        for (int k = 0; k < c1000.size(); k++)
            cout << c1000[c1000.size() - k - 1];
        cout << endl;
    }

    int sum = 0;
    for (int i = 0; i < c1000.size(); i++)
    {
        sum += int(c1000[i] - '0');
    }
    cout << sum << endl;

    return 0;
}

