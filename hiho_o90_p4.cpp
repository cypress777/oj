#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int is_valid(const string &a) {
    if (a.size() == 1 && a[0] == 'n') return -1;
    int num = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] - '0' < 0 || a[i] - '9' > 0) return -2;
        num *= 10;
        num += a[i] - '0';
    }
    return num;
}

int main() {
    int N;
    cin >> N;

    unordered_set<char> params_set;
    vector<int> loop_times;
    vector<char> param_que;

    int complexity = 0;
    int flag = 1;
    for (int i = 0; i < N; i++) {
        string state;
        cin >> state;

        if (state[0] == 'F') {
            string arg, x, y;
            cin >> arg >> x >> y;

            if (arg.size() != 1) continue;

            int xx = is_valid(x);
            int yy = is_valid(y);
            if (params_set.find(arg[0]) != params_set.end() || xx == -2 || yy == -2) {
                flag = -1;
                break;
            } else {
                params_set.insert(arg[0]);
                param_que.push_back(arg[0]);
                if (xx == -1 && yy == -1 || yy != -1 && xx != -1 && yy - xx >= 0) {
                    loop_times.push_back(0);
                } else if (xx == -1 && yy != -1 || yy != -1 && xx != -1 && xx - yy > 0) {
                    loop_times.push_back(-1);
                } else if (yy == -1) {
                    loop_times.push_back(1);
                }
            }
            cout << state[0] << " " << arg[0] << " " << x << " " << y << endl;
        } else if (state[0] == 'E') {
            cout << state[0] << endl;
            int size = param_que.size();
            if (size == 0) {
                flag = -1;
                break;
            } else {
                params_set.erase(param_que[size - 1]);
                param_que.pop_back();
                int pow  = 0;
                for (int k = 0; k < loop_times.size(); k++) {
                    cout << loop_times[k] << endl;
                }
                for (int k = 0; k < loop_times.size(); k++) {
                    if (loop_times[k] == -1) break;
                    pow += loop_times[k];
                }
                loop_times = vector<int>{};
                complexity = complexity > pow ? complexity : pow;
            }
        }
    }

    if (flag == -1) {
        cout << "CE" << endl;
    } else {
        cout << "O(n^" << to_string(complexity) << ")" << endl;
    }

    return 0;
}