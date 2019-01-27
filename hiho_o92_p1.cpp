#include <iostream>
#include <vector>

using namespace std;

int N;
vector<char> le;
vector<int> pa;
vector<int> ch;

int main() {
    cin >> N;

    le = vector<char> (N + 1, 'A');
    pa = vector<int>(N + 1, -1);
    ch = vector<int>(N + 1, -1);

    for (int i = 1; i <= N; i++) {
        string s;
        int p;
        cin >> s >> p;

        le[i] = s[0];
        pa[i] = p;
        ch[p] = 1;
    }

    vector<int> ss;
    vector<vector<int>> que(N + 1, vector<int>(N, -1));
    int t = 0;
    int f = -1;
    for (int i = 1; i <= N; i++) {
        if (ch[i] == -1) {
            if (f == -1 || f >= 0 && le[que[t][f]] == le[i]) {
                f++;
                que[t][f] = i;
            } else if (le[que[t][f]] > le[i]) {
                f = 0;
                que[t][f] = i;
            }
            // cout << f << " " << que[t][f] << " " << le[que[t][f]] << endl;
        }
    }
    ss.push_back(que[t][f]);

    int tt = 1;
    int ff = -1;
    while (true) {
        if (pa[que[t][f]] == 0) break;

        if (ff == -1 || ff >= 0 && le[que[tt][ff]] == le[pa[que[t][f]]]) {
            ff++;
            que[tt][ff] = pa[que[t][f]];
        } else if (le[que[tt][ff]] > le[pa[que[t][f]]]) {
            ff = 0;
            que[tt][ff] = pa[que[t][f]];
        }
        // cout << ff << " " << que[tt][ff] << " " << le[que[tt][ff]] << endl;
        f--;

        if (f == -1) {
            ss.push_back(que[tt][ff]);
            t++;
            tt++;
            f = ff;
            ff = -1;
        }
    }

    for (int i = 0; i < ss.size(); i++) {
        cout << le[ss[i]];
    }
    cout << endl;

    return 0;
}