#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_vec(vector<int> a) {
    for (auto aa : a) cout << aa << "  " << endl;
    cout << endl;
}

// We have to sort population of all stars dynamically, so heapsort would be the best practice.
// Besides the population of these stars is changing yearly, refresh the heap all the time is too costly.
// Instead of refreshing the heap, we use a global param CUR indicating the Yth century;

int N, M, K, CUR;

class Star {
    public:
    int p_;
    int t_;
    Star(int p, int t) : p_(p), t_(t) {}
    Star() : p_(0), t_(0) {};

    int get_cur_p() const {
        return this->p_ + (CUR - this->t_) * K * 100; 
    }
};

void insert(Star s, vector<Star> &uni) {
    uni.push_back(s);
    int i = uni.size() - 1;
    while (i > 1) {
        int j = i / 2;
        if (uni[i].get_cur_p() > uni[j].get_cur_p()) {
            Star tmp;
            tmp = uni[i];
            uni[i] = uni[j];
            uni[j] = tmp;
            i = j;
        } else {
            break;
        }
    }
}

void update(vector<Star> &uni) {
    int i = 1;
    while(i * 2 < uni.size()) {
        int j = i * 2;
        if (j + 1 < uni.size() && uni[j + 1].get_cur_p() > uni[j].get_cur_p()) j++;
        if (uni[i].get_cur_p() < uni[j].get_cur_p()) {
            Star tmp;
            tmp = uni[i];
            uni[i] = uni[j];
            uni[j] = tmp;
            i = j;
        } else {
            break;
        }
    }
}

int main() {
    // N stars; M centuries; K increasement per year.
    cin >> N >> M >> K;
    vector<Star> universe{};

    universe.push_back(Star{});
    CUR = 0; // !!!!!!!!!! initialization !!!!!!!!
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        Star s(p, 0);
        insert(s, universe);
        // for (int i = 1; i < universe.size(); i++) {
        //     cout << universe[i].p_ << " " << universe[i].t_ << " " << universe[i].get_cur_p() << endl;
        // }
    }

    for (CUR = 1; CUR <= M; CUR++) {
        int p = universe[1].get_cur_p();
        p /= 2;
        universe[1].p_ = p;
        universe[1].t_ = CUR;
        update(universe);
        // for (int i = 1; i < universe.size(); i++) {
        //     cout << universe[i].p_ << " " << universe[i].t_ << " " << universe[i].get_cur_p() << endl;
        // }
    }
    CUR--; // !!!!!!!!!! last loop minus 1 !!!!!!!!!!

    long long sum = 0; // !!!!!!!!!!!!!! AGAIN over the int range!!!!!!!!!
    for (int i = 1; i < universe.size(); i++) {
        sum += static_cast<long long>(universe[i].get_cur_p()); // !!!!!!!!! range !!!!!!!!!
    }

    cout << sum << endl;
}