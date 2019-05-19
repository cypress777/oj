#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct priority_queue {
    explicit priority_queue() {
        queue_ = vector<int>(1);
        r_ = 0;
    }

    void push(int v) {
        r_++;
        if (queue_.size() == r_) queue_.push_back(v);
        else queue_[r_] = v;
        up();
    }

    void pop() {
        if (r_ < 1) return;
        queue_[1] = queue_[r_];
        r_--;
        down();
    }

    int top() {
        if (r_ < 1) return -1;
        return queue_[1];
    }

    void down() {
        int id = 1;
        while (id < r_) {
            int nid = id;
            if (id * 2 <= r_ && queue_[nid] > queue_[id * 2]) nid = id * 2;
            if (id * 2 + 1 <= r_ && queue_[nid] > queue_[id * 2 + 1]) nid = id * 2 + 1;
            if (id == nid) break;
            int tmp = queue_[id];
            queue_[id] = queue_[nid];
            queue_[nid] = tmp;
            id = nid;
        }
    }

    void up() {
        int id = r_;
        while (id > 1) {
            if (queue_[id] >= queue_[id / 2]) break;
            int tmp = queue_[id];
            queue_[id] = queue_[id / 2];
            queue_[id / 2] = tmp;
            id = id / 2;
        }
    }

    int r_;
    vector<int> queue_;
};

int N, M;
vector<int> A;
vector<vector<int>> P;
priority_queue choices;

int main() {
    cin >> N >> M;

    A = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    P = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> P[i][j];
        }
        sort(P[i].begin(), P[i].end());
        for (int j = 0; j < M; j++) {
            P[i][j] += 2 * j + 1;
        }
    }

    long long spent = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            choices.push(P[i][j]);
        }

//        cout << "------ " << i << endl;
//
//        for (int c : choices.queue_) cout << c << " ";
//        cout << endl;
//        cout << choices.top() << endl;

        for (int j = 0; j < A[i]; j++) {
            spent += choices.top();
            choices.pop();
        }

//        for (int c : choices.queue_) cout << c << " ";
//        cout << endl;
    }

    cout << spent << endl;

    return 0;
}

