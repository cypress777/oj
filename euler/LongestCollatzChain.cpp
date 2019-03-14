//
// Created by cypress on 2018/8/19.
//

#include <iostream>
#include <vector>

using namespace std;

int getChainLen(long N, vector<int>& chainLength)
{
    if (chainLength.size() > N && chainLength[N] != 0)
        return chainLength[N];

    int len = 0;
    if (N == 1)
        len = 1;
    else if (N%2 == 0)
        len = 1 + getChainLen(N/2, chainLength);
    else
        len = 1 + getChainLen(3*N + 1, chainLength);


    if (N < chainLength.size())
        chainLength[N] = len;

    return len;
}

int main()
{
    vector<int> chainLength(1000001, 0);
    int maxLen = 0;
    int maxIdx = 0;
    for (int i = 999999; i > 0; i--)
    {
        int len = getChainLen(i, chainLength);
        if (len > maxLen)
        {
            maxLen = len;
            maxIdx = i;
        }
    }

    cout << "idx: " << maxIdx << " len: " << maxLen << endl;
    return 1;
}