#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>

using namespace std;

int gcd(int a, int b) {
    int t = 1;
    int m = max(a, b);
    int n = min(a, b);
    while (n != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

struct Number {
    int n_, d_;

    Number(int n, int d) {
        if (n == 0) {
            n_ = 0;
            d_ = 1;
        } else {
            int g = gcd(n, d);
            n_ = n / g;
            d_ = d / g;
        }
    }

    Number operator*(const int &other) {
        return Number(this->n_ * other, this->d_);
    }

    Number operator*(const Number &other) {
        return Number(this->n_ * other.n_, this->d_ * other.d_);
    }

    Number operator+(const Number &other) {
        return Number(this->n_ * other.d_ + other.n_ * this->d_, this->d_ * other.d_);
    }

    Number operator-(const Number &other) {
        return Number(this->n_ * other.d_ - other.n_ * this->d_, this->d_ * other.d_);
    }

    Number operator/(const Number &other) {
        return Number(this->n_ * other.d_, (this->d_ * other.n_));
    }

    bool operator==(const Number &other) {
        return this->n_ == other.n_ && this->d_ == other.d_;
    }
};

int main() {
    vector<int> A = {5248, 5760, 7872};
    vector<int> B = {640, 3776, 11328};

    int tot_a = 0;
    for (auto a : A) tot_a += a;

    int tot_b = 0;
    for (auto b : B) tot_b += b;

    Number max_res(0, 1);
    Number min_res(1000, 1);

    set<string> all_res;

    for (int i = 1; i <= B[0]; i++) {
        for (int j = 1; j <= i * A[0] / B[0]; j++) {
            Number factor = Number(i, B[0]) / Number(j, A[0]);
            string sfactor = to_string(factor.n_) + "/" + to_string(factor.d_);

            if (factor.n_ <= factor.d_) continue;
            if (all_res.find(sfactor) != all_res.end()) continue;

            bool found = false;

            for (int k = 1; k <= B[1]; k++) {
                if (found) break;

                Number next_num = Number(k * A[1], B[1]) / factor;

                if (next_num.d_ == 1) {
                    int a1 = next_num.n_;

                    for (int l = 1; l <= B[2]; l++) {
                        if (found) break;

                        next_num = Number(l * A[2], B[2]) / factor;

                        if (next_num.d_ == 1) {
                            int a2 = next_num.n_;

                            if (Number(j + a1 + a2, tot_a) / Number(i + k + l, tot_b) == factor) {
                                Number ratio = (factor / max_res);
                                if (ratio.n_ > ratio.d_) max_res = factor;

                                ratio = (factor / min_res);
                                if (ratio.n_ < ratio.d_) min_res = factor;

                                all_res.insert(sfactor);

                                found = true;

                                cout << "---- res: " << endl;
                                cout << i << " " << k << " " << l << " " << j << " " << a1 << " " << a2 << endl;
                                cout << sfactor << " " << all_res.size() << endl;
                                cout << "cur " << factor.n_ << " " << factor.d_ << endl;
                                cout << "max " << max_res.n_ << " " << max_res.d_ << endl;
                                cout << "min " << min_res.n_ << " " << min_res.d_ << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

