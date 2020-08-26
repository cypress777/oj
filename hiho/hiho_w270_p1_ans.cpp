#include <iostream>
#include <list>
#include <cmath>
using namespace std;

const double eps = 1e-6;

struct Node {
    int width;
    double height;
    int p, q;

    Node(int w, double h, int p_, int q_) {
        width = w;
        height = h;
        p = p_;
        q = q_;
    }
};

int n, s, t, t_h;
double m;

list<Node> a;
list<Node>::iterator head_iter, tail_iter;

double get_potential(list<Node>::iterator iter) {
    if (iter == head_iter || iter == tail_iter) return 1e18;

    auto left = iter;
    left--;
    auto right = iter;
    right++;

    double hdiff;
    if (left->height < right->height) hdiff = left->height - iter->height;
    else hdiff = right->height - iter->height;

    return hdiff * iter->width;
}

list<Node>::iterator get_left(list<Node>::iterator mid) {
    auto left = mid;
    while (left != head_iter) {
        auto next = left;
        next--;
        if (next->height > left->height + eps) break;
        left = next;
    }
    return left;
}

list<Node>::iterator get_right(list<Node>::iterator mid) {
    auto right = mid;
    while (right != tail_iter) {
        auto next = right;
        next++;
        if (next->height > right->height + eps) break;
        right = next;
    }
    return right;
}

void expand(list<Node>::iterator iter, list<Node>::iterator &mid, list<Node>::iterator &other) {
    if (iter != head_iter) {
        auto left = iter;
        left--;
        if (fabs(iter->height - left->height) < eps) {
            iter->p = left->p;
            iter->width += left->width;
            if (mid == left) mid = iter;
            if (other == left) other = iter;
            a.erase(left);
        }
    }

    if (iter != tail_iter) {
        auto right = iter;
        right++;
        if (fabs(iter->height - right->height) < eps) {
            iter->q = right->q;
            iter->width += right->width;
            if (mid == right) mid = iter;
            if (other == right) other = iter;
            a.erase(right);
        }
    }
}

int main() {
    cin >> n >> s >> m >> t;

    Node head(1, -1e18, 0, 0);
    Node tail(1, -1e18, n + 1, n + 1);

    a.push_back(head);

    auto last = a.begin();
    list<Node>::iterator mid;
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        if (h == last->height) {
            last->width++;
            last->q = i;
        } else {
            Node cur(1, h, i, i);
            a.push_back(cur);
            last++;
        }
        if (i == s) mid = last;
        if (i == t) t_h = h;
    }

    a.push_back(tail);

    auto left = get_left(mid);
    auto right = get_right(mid);

    head_iter = a.begin();
    tail_iter = a.end();
    tail_iter--;

    while (m > 0) {
        if (mid == right) {
            double potential = get_potential(left);
            if (potential >= m) {
                left->height += m / left->width;
                m = 0;
            } else {
                left->height += potential / left->width;
                m -= potential;
            }
        } else if (mid == left) {
            double potential = get_potential(right);
            if (potential >= m) {
                right->height += m / right->width;
                m = 0;
            } else {
                right->height += potential / right->width;
                m -= potential;
            }
        } else {
            double potential = min(get_potential(left), get_potential(right));
            if (potential * 2 >= m) {
                left->height += m / 2 / left->width;
                right->height += m / 2 / right->width;
                m = 0;
            } else {
                left->height += potential / left->width;
                right->height += potential / right->width;
                m -= potential * 2;
            }
        }

        expand(left, mid, right);
        expand(right, mid, left);

        left = get_left(left);
        right = get_right(right);
    }

    auto iter = head_iter;
    while (iter->p > t || iter->q < t) iter++;

    cout << int(floor(iter->height + eps)) - t_h << endl;

    return 0;
}