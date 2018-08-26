//
// Created by cypress on 2018/8/25.
//
#include "LargeNumHelper.hpp"

using namespace std;

vector<char> largeNumSum(const vector<char>& a, const vector<char>& b)
{
    int aLen = a.size();
    int bLen = b.size();
    vector<char> res(max(aLen, bLen) + 1, '0');
    int carry = 0;
    int sum = 0;

    for (int i = 0; i < max(aLen, bLen) + 1; i++)
    {
        sum = i < aLen ? int(a[i] - '0') : 0;
        sum += i < bLen ? int(b[i] - '0') : 0;
        sum = sum + carry;

        res[i] = char(sum % 10 + '0');
        carry = sum / 10;
    }

    return res;
}

vector<char> largeNumSubtraction(const vector<char>& a, const vector<char>& b)
{
    int aLen = a.size();
    int bLen = b.size();
    bool exchange = false;


    for (int i = max(aLen, bLen) - 1; i > -1; i--)
    {
        if (i > bLen - 1 && a[i] != 0)
        {
            exchange = false;
            break;
        }
        else if (i > aLen - 1 && b[i] != 0)
        {
            exchange = true;
            break;
        }
        if (a[i] > b[i])
        {
            exchange = false;
            break;
        }
        else if (a[i] < b[i])
        {
            exchange = true;
            break;
        }
    }

    vector<char> res(max(aLen, bLen) + 1, '0');

    int borrow = 0;

    if (!exchange)
    {
        for (int i = 0; i < max(aLen, bLen); i++)
        {
            int aVal = i < aLen ? int(a[i] - '0') : 0;
            aVal -= borrow;
            int bVal = i < bLen ? int(b[i] - '0') : 0;

            int reminder = aVal > bVal || aVal == bVal ? aVal - bVal : 10 + aVal - bVal;
            borrow = aVal > bVal || bVal == aVal ? 0 : 1;
            res[i] = char(reminder + '0');
        }
    }
    else
    {
        int i = 0;
        for (i = 0; i < max(aLen, bLen); i++)
        {
            int aVal = i < aLen ? int(a[i] - '0') : 0;
            int bVal = i < bLen ? int(b[i] - '0') : 0;
            bVal -= borrow;

            int reminder = bVal > aVal || bVal == aVal ? bVal - aVal : 10 + bVal - aVal;
            borrow = bVal > aVal || bVal == aVal ? 0 : 1;
            res[i] = char(reminder + '0');
        }
        res[i] = '-';
    }

    return res;
}

vector<char> largeNumMult(const vector<char>& a, const vector<char>& b)
{
    int aLen = a.size();
    int bLen = b.size();
    vector<vector<char>> tmpRes(aLen, vector<char>(aLen + bLen + 1, '0'));
    vector<char> res(aLen + bLen + 1, '0');

    for (int i = 0; i < aLen; i++)
    {
        int carry = 0;
        int j = 0;
        for (j = 0; j < bLen; j++)
        {
            int mult = int(b[j] - '0') * int(a[i] - '0') + carry;
            tmpRes[i][i + j] = char(mult % 10 + '0');
            carry = mult / 10;
        }
        tmpRes[i][i + j] = char(carry + '0');
    }

    for (int i = 0; i < aLen - 1; i++)
    {
        vector<char> sum;
        sum = largeNumSum(tmpRes[i], tmpRes[i + 1]);
        for (int j = 0; j < tmpRes[i].size(); j++)
            tmpRes[i+1][j] = sum[j];
    }

    for (int i = 0; i < aLen + bLen + 1; i++)
        res[i] = tmpRes[aLen - 1][i];

    return res;
}