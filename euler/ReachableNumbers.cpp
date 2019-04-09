#include <vector>
#include <iostream>
#include <set>

using namespace std;

struct Number {
    long long n_;
    long long d_;
    Number(long long n, long long d) {
        if (n == 0) {
            n_ = 0;
            d_ = 1;
        } else {
            long long g = gcd(abs(n), abs(d));
            n /= g;
            d /= g;
            if (n * d < 0) {
                n_ = -1 * abs(n);
            } else {
                n_ = abs(n);
            }
            d_ = abs(d);
        }
    }

    Number operator+(const Number &other) {
        return Number(this->n_ * other.d_ + this->n_ * other.d_, this->d_ * other.d_);
    }

    Number operator-(const Number &other) {
        return Number(this->n_ * other.d_ - this->n_ * other.d_, this->d_ * other.d_);
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

bool operator<(const Number &a, const Number &b) {
    return a.n_ * b.d_ < b.n_ * a.d_;
}

set<Number> get_result(const vector<int> &array) {
    set<Number> results;
    if (array.size() == 1) {
        results.insert(Number((long long)array[0], 1l));
        return results;
    }
    long long num = 0;
    for (int i = 0; i < array.size(); i++) num = num * 10 + array[i];
    results.insert(Number(num, 1l));

    for (int i = 0; i < array.size() - 2; i++) {
        cout << " ------------" << endl;
        vector<int> arr_a;
        for (int j = 0; j <= i; j++) cout << array[j] << " ";
        cout << endl;

        for (int j = 0; j <= i; j++) arr_a.push_back(array[j]);
        auto res_a = get_result(arr_a);

        vector<int> arr_b;
        for (int j = i + 1; j < array.size() - 1; j++) cout << array[j] << " ";
        cout << endl;

        for (int j = i + 1; j < array.size() - 1; j++) arr_b.push_back(array[j]);
        auto res_b = get_result(arr_b);

        for (Number a : res_a) {
            for (Number b : res_b) {
                results.insert(a + b);
                results.insert(a - b);
                results.insert(a * b);
                if (b.n_ != 0) results.insert(a / b);
            }
        }
    }

    return results;
}

int main() {
    set<Number> results = get_result({1, 2, 3, 4, 5, 6, 7, 8, 9});

    long long total = 0;
    for (auto s : results) {
        if (s.d_ == 1 && s.n_ > 0) total += s.n_;
    }

    cout << total << endl;

    return 0;
}

