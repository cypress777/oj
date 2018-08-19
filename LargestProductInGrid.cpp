//
// Created by cypress on 2018/8/19.
//
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fnum;
    fnum.open(argv[1], ios::in);
    if (!fnum.is_open()) return -1;

    vector<vector<int>> allNums;

    string nums;
    int row = 0;
    while(getline(fnum, nums))
    {
        vector<int> rowNums;
        int scale = 10;
        int num = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int tmpnum = (int)nums[i] - 48;

            if (tmpnum != -16)
            {
                num += tmpnum * scale;
                scale = scale/10;
            }

            if (tmpnum == -16)
            {
                rowNums.push_back(num);
                scale = 10;
                num = 0;
            }
        }
        allNums.push_back(rowNums);
        row++;
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << allNums[i][j] << " ";
        }
        cout << endl;
    }

    long maxProduct = 1;
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            long product1 = allNums[i][j] * allNums[i][j+1] * allNums[i][j+2] * allNums[i][j+3];
            long product2 = allNums[i][j] * allNums[i+1][j] * allNums[i+2][j] * allNums[i+3][j];
            long product3 = allNums[i][j] * allNums[i+1][j+1] * allNums[i+2][j+2] * allNums[i+3][j+3];
            long product4 = allNums[i][j+3] * allNums[i+1][j+2] * allNums[i+2][j+1] * allNums[i+3][j];

            if (product1 > maxProduct) maxProduct = product1;
            if (product2 > maxProduct) maxProduct = product2;
            if (product3 > maxProduct) maxProduct = product3;
            if (product4 > maxProduct) maxProduct = product4;
        }
    }

    cout << maxProduct << endl;
}