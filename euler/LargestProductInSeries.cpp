//
// Created by cypress on 2018/8/19.
//
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fnum;
    fnum.open(argv[1], ios::in);
    if (!fnum.is_open()) return -1;

    vector<int> allNums;

    string nums;
    while(getline(fnum, nums))
    {
        for (int i = 0; i < nums.size(); i++)
        {
            char a = nums[i];
            int tmpnum = (int)a - 48;
            allNums.push_back(tmpnum);
        }
    }


    long maxProduct = 1;
    for (int i = 0; i < allNums.size() - 12; i++)
    {
        long product = 1;
        for (int j = 0; j < 13; j++)
        {
            product *= allNums[i + j];
        }
        if (product > maxProduct) maxProduct = product;
    }

    cout << maxProduct << endl;
    return 1;
}
