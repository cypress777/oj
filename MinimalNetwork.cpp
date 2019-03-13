#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N = 40;
int MM = 1000000000;

void method_1() {
    vector<vector<int>> graph;
    vector<int> dist;
    vector<int> flg;

    ifstream fin("p107_network.txt", fstream::in);

    dist = vector<int>(N, MM);
    flg = vector<int>(N, -1);
    graph = vector<vector<int>>(N, vector<int>(N, -1));

    int total = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int n;
        fin >> n;
        if (n == -1) {
            graph[i][j] = MM;
        } else {
            graph[i][j] = n;
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
        for (int i = 0; i < N; i++) if (flg[i] == -1 && dist[i] <= min_dist) min_dist = dist[i], min_id = i;
        for (int i = 0; i < N; i++) dist[i] = dist[i] > graph[i][min_id] ? graph[i][min_id] : dist[i];

        flg[min_id] = 1;
        route += min_dist;
        count++;
    }
    cout << total << " " << route << " " << total - route << endl;
}

struct edges {
    int x, y, v;
    edges(int x_, int y_, int v_) : x(x_), y(y_), v(v_) {};
    edges() {};
};

vector<edges> e;
vector<int> f;
vector<int> s;

bool comp(edges a, edges b) {
    return a.v < b.v;
}

int get_f(int n) {
    if (f[n] == -1) return n;
    f[n] = get_f(f[n]);
    return f[n];
}

void method_2() {
    f = vector<int>(N, -1);
    s = vector<int>(N, 1);
    ifstream fin("p107_network.txt", fstream::in);

    int total = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int n;
        fin >> n;
        if (n > 0 && i < j) total += n, e.emplace_back(edges(i, j, n));
    }

    sort(e.begin(), e.end(), comp);

    int route = 0;
    for (auto edge : e) {
        int fx = get_f(edge.x);
        int fy = get_f(edge.y);
        if (fx != fy) {
            route += edge.v;
            if (s[fx] > s[fy]) {
                f[fy] = fx;
                s[fx] += s[fy]; 
            } else {
                f[fx] = fy;
                s[fy] += s[fx];
            }
        }
    }
    cout << total << " " << route << " " << total - route << endl;
}

int main() {
    method_1();
    method_2();
    return 0;
}