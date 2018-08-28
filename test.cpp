//
// Created by cypress on 2018/8/26.
//

#include <iostream>
#include <vector>
#include "LargeNumHelper.hpp"

using namespace std;

int main()
{
    vector<char> a{'1', '4', '5'};
    vector<char> b{'6', '7', '2'};
    vector<char> c = largeNumMult(b, b);
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;
    mutLargeNumSum(a, b);
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    cout << endl;
    mutLargeNumSubtraction(b, a);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    mutLargeNumMult(a, a);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}
