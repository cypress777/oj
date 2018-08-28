//
// Created by cypress on 2018/8/28.
//

#include <iostream>
#include "LargeNumHelper.hpp"

using namespace std;

int main()
{
    vector<char> a{'1'};
    vector<char> b{'1'};
    vector<char> c;

    int count = 2;
    while (b.size() < 1000)
    {
        c = b;
        mutLargeNumSum(a, b);
        count++;
        a.swap(c);
    }
    cout << "res: " << count << endl;
}