#include <iostream>
#include <vector>

using namespace std;

int N;
int MM = 1000000;
vector<int> all_dist;
vector<vector<int>> dist;
vector<char> map;
vector<int> cities;
int cen;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

void get_dist(int a) {
    vector<int> flags(N * N, -1);
    vector<int> que;

    all_dist[a] = 0;
    que.push_back(a);
    flags[a] = 1;

    int r = 0;
    int f = 0;

    while (r <= f) {
        int id = que[r];
        int x = id / N;
        int y = id % N;
        r++;
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            int iid = xx * N + yy;
            if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
                if (flags[iid] == -1) {
                    flags[iid] = 1;
                    int ext = 1;
                    char sym = map[iid];
                    if (sym == '#') continue;
                    if (all_dist[id] + ext < all_dist[iid]) all_dist[iid] = all_dist[id] + ext;

                    que.push_back(iid);
                    f++;
                }
            }
        }
    }
}

int main() {
    cin >> N;

    map = vector<char>(N * N, '.');

    for (int i = 0; i < N; i++) {
        string sym;
        cin >> sym;
        for (int j = 0; j < N; j++) {
            map[i * N + j] = sym[j];
            if (map[i * N + j] == 'c' || map[i * N + j] == 'C') cities.push_back(i * N + j);
            if (map[i * N + j] == 'C') cen = i * N + j;
        }
    }

    int num = cities.size();
    dist = vector<vector<int>>(num, vector<int>(num, MM));

    for (int i = 0; i < cities.size(); i++) {
        all_dist = vector<int>(N * N, MM);
        int a = cities[i];
        get_dist(a);
        dist[i][i] = 0;
        for (int j = 0; j < cities.size(); j++) {
            dist[i][j] = all_dist[cities[j]];
            dist[j][i] = dist[i][j];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> P(num, MM);
    int tree = 0;
    int spent = 0;
    while(tree < num) {
        int min = MM;
        int id = -1;
        for (int i = 0; i < num; i++) {
            if (P[i] != 0 && P[i] <= min) {
                min = P[i];
                id = i;
            }
        }
        tree++;
        if (tree > 1) spent += P[id];
        P[id] = 0;

        for (int i = 0; i < num; i++) {
            if (P[i] > dist[id][i]) P[i] = dist[id][i];
        }
    }

    cout << spent << endl;

    return 0;
}