#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<long long> colin;
vector<long long> peter;
long long tot_colin;
long long tot_peter;

void cal_colin(long long n, long long val) {
    if (n == 0) {
        colin[val]++;
    } else {
        for (long long i = 1; i <= 4; i++) {
            long long new_val = val + i;
            cal_colin(n - 1, new_val);
        }
    }
}

void cal_peter(long long n, long long val) {
    if (n == 0) {
        peter[val]++;
    } else {
        for (long long i = 1; i <= 6; i++) {
            long long new_val = val + i;
            cal_peter(n - 1, new_val);
        }
    }
}

struct Number {
    long long n_, d_;
    Number() {}
    Number(long long n, long long d) {
        cout << "--- " << n << " " << d << endl;
        if (n == 0) {
            n_ = 0;
            d_ = 1;
        } else {
            long long symbol = 1;
            if (n * d < 0) symbol = -1;

            long long g = gcd(abs(n), abs(d));
            n_ = symbol * (abs(n) / g);
            d_ = abs(d) / g;
        }
        cout << "=== " << n_ << " " << d_ << endl;
    }

    Number operator+(const Number &other) {
        return Number(this->n_ * other.d_ + other.n_ * this->d_, this->d_ * other.d_);
    }

    Number operator-(const Number &other) {
        return Number(this->n_ * other.d_ - other.n_ * this->d_, this->d_ * other.d_);
    }

    Number operator*(const Number &other) {
        return Number(this->n_ * other.n_, this->d_ * other.d_);
    }

    Number operator/(const Number &other) {
        return Number(this->n_ * other.d_, this->d_ * other.n_);
    }

    long long gcd(long long a, long long b) {
        long long t = 1;
        long long m = max(a, b);
        long long n = min(a, b);
        while (n != 0) {
            t = m % n;
            m = n;
            n = t;
        }
        return m;
    }
};

int main() {
    colin = vector<long long>(37, 0);
    peter = vector<long long>(37, 0);

    tot_colin = pow(4, 9);
    tot_peter = pow(6, 6);

    cal_colin(9, 0);
    cal_peter(6, 0);

    double tot_p = 0;
    for (long long i = 9; i <= 36; i++) {
        double p_colin = (double)colin[i] / (double)tot_colin;
        double p_peter = 0;
        for (long long j = 6; j < i; j++) {
            p_peter = p_peter + (double)peter[j] / (double)tot_peter;
        }
        tot_p = tot_p + p_colin * p_peter;
    }

    cout << fixed << setprecision(8) << tot_p << endl;

    return 0;
}

