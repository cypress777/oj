#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int get_num(const string &a) {
    if (a.size() == 1 && a[0] == 'n') return -1;
    int num = 0;
    for (int i = 0; i < a.size(); i++) {
        num *= 10;
        num += a[i] - '0';
    }
    return num;
}

int main() {
    int N;
    cin >> N;

    unordered_set<string> params_set;
    vector<int> loop_times(1, 0);
    vector<string> param_que;

    int complexity = 0;
    int flag = 1;
    for (int i = 0; i < N; i++) {
        string state;
        cin >> state;

        if (state[0] == 'F') {
            string arg, x, y;
            cin >> arg >> x >> y;

            int xx = get_num(x);
            int yy = get_num(y);
            if (params_set.find(arg) != params_set.end()) {
                flag = -1;
                break;
            } else {
                int cur_dep = param_que.size();
                params_set.insert(arg);
                param_que.push_back(arg);
                if (loop_times[cur_dep] == -1) {
                    loop_times.push_back(-1);
                } else if (xx == -1 && yy == -1 || yy != -1 && xx != -1 && yy - xx >= 0) {
                    loop_times.push_back(loop_times[cur_dep]);
                } else if (xx == -1 && yy != -1 || yy != -1 && xx != -1 && xx - yy > 0) {
                    loop_times.push_back(-1);
                } else if (yy == -1) {
                    loop_times.push_back(loop_times[cur_dep] + 1);
                }
            }
            // cout << state[0] << " " << arg[0] << " " << x << " " << y << endl;
            // for (int i = 0; i < loop_times.size(); i++) {
            //     cout << loop_times[i] << " ";
            // }
            // cout << endl;
        } else if (state[0] == 'E') {
            // cout << state[0] << endl;
            int size = param_que.size();
            if (size == 0) {
                flag = -1;
                break;
            } else {
                params_set.erase(param_que[size - 1]);
                param_que.pop_back();
                complexity = complexity > loop_times[size] ? complexity : loop_times[size];
                loop_times.pop_back();
            }
            // for (int i = 0; i < loop_times.size(); i++) {
            //     cout << loop_times[i] << " ";
            // }
            // cout << endl;
        }
    }

    if (param_que.size() != 0) flag = -1;

    if (flag == -1) {
        cout << "CE" << endl;
    } else {
        if (complexity == -1) complexity = 0;
        if (complexity == 0) {
            cout << "O(1)" << endl;
        } else if (complexity == 1) {
            cout << "O(n)" << endl;
        } else {
            cout << "O(n^" << to_string(complexity) << ")" << endl;
        }
    }

    return 0;
}