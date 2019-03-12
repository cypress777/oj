#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> dist;
vector<int> flg;
int N = 40;
int MM = 1000000000;

int main() {
    dist = vector<int>(N, MM);
    flg = vector<int>(N, -1);
    graph = vector<vector<int>>(N, vector<int>(N, -1));

    int total = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int n;
        cin >> n;
        if (n = -1) {
            graph[i][j] = MM;
        } else {
            total += n;
        }
    }
    total /= 2;

    flg[0] = 1;
    for (int i = 0; i < N; i++) dist[i] = dist[i] > graph[i][0] ? graph[i][0] : dist[i];
    int count = 1;

    int route = 0;
    while (count < N) {
        int min_id = -1;
        int min_dist = MM;
        for (int i = 0; i < N; i++) if (flg[i] == -1 && dist[i] < min_dist) min_dist = dist[i], min_id = i;

        flg[min_id] = 1;
        route += min_dist;
        N++;
    }
}