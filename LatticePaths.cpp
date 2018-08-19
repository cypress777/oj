//
// Created by cypress on 2018/8/20.
//
#include <iostream>
#include <vector>

using namespace std;

long numPaths(int x, int y, vector<vector<long>>& paths)
{
    if (x < paths.size() && y < paths[0].size() && (paths[x][y] != -1 || paths[y][x] != -1))
    {
        if (paths[x][y] != -1)
        {
            if  (paths[y][x] == -1)
                paths[y][x] = paths[x][y];
            return paths[x][y];
        }
        else
        {
            paths[x][y] = paths[y][x];
            return paths[y][x];
        }
    }

    if (x == paths.size() - 1 && y == paths[0].size() - 1)
    {
        paths[x][y] = 0;
        return 0;
    }

    if (x > paths.size() - 1 || y > paths[0].size() - 1) return 0;

    else if (x == paths.size() - 1 || y == paths[0].size() - 1){
        paths[x][y] = 1;
        paths[y][x] = 1;
        return 1;
    }

    long num = numPaths(x + 1, y, paths) + numPaths(x, y + 1, paths);

    paths[x][y] = num;
    if (x != y)
        paths[y][x] = num;

    return num;
}


int main()
{
    int size = 2 + 1;
    vector<vector<long>> paths;

    for (int i = 0; i < size; i++)
    {
        vector<long> tmp(size, -1);
        paths.push_back(tmp);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << paths[i][j] << " ";
        cout << endl;
    }

    long num = numPaths(0, 0, paths);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << paths[i][j] << " ";
        cout << endl;
    }

    cout << num << endl;
    return 1;
}