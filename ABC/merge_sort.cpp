#include <vector>
#include <iostream>
#include <chrono>

int check_a;
int check_b;

void print_vector(const std::vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) std::cout << v[i] << " ";
    std::cout << v[v.size() - 1] << std::endl;
}

void merge_sort_two(const std::vector<int> &A, const std::vector<int> &B, std::vector<int> &C) {
    int ra = 0;
    int rb = 0;
    while (ra < A.size() || rb < B.size()) {
        if (ra == A.size()) {
            for (int i = rb; i < B.size(); i++) C.push_back(B[i]);
            break;
        } else if (rb == B.size()) {
            for (int i = ra; i < A.size(); i++) C.push_back(A[i]);
            break;
        } else if (A[ra] <= B[rb]) {
            C.push_back(A[ra]);
            ra++;
        } else {
            C.push_back(B[rb]);
            rb++;
        }
    }
}

void up(std::vector<int> &h, int f, const std::vector<int> &curs, const std::vector<std::vector<int>> &data) {
    int id = f;
    while (id > 1) {
        if (data[h[id]][curs[h[id]]] < data[h[id / 2]][curs[h[id / 2]]]) {
            int tmp = h[id];
            h[id] = h[id / 2];
            h[id / 2] = tmp;
            id /= 2;
        } else {
            break;
        }
    }
}

void down(std::vector<int> &h, int f, const std::vector<int> &curs, const std::vector<std::vector<int>> &data) {
    int id = 1;
    while (id < f) {
        int nid = id;
        if (id * 2 + 1 <= f && data[h[id * 2 + 1]][curs[h[id * 2 + 1]]] < data[h[id]][curs[h[id]]])
            nid = id * 2 + 1;
        if (id * 2 <= f && data[h[id * 2]][curs[h[id * 2]]] < data[h[nid]][curs[h[nid]]])
            nid = id * 2;
        if (id == nid) break;
        int tmp = h[id];
        h[id] = h[nid];
        h[nid] = tmp;
        id = nid;
    }
}

void merge_sort(const std::vector<std::vector<int>> &data, std::vector<int> &out) {
    std::vector<int> curs(data.size(), 0);
    std::vector<int> h(data.size() + 1);
    int r = 1, f = 0;
    for (int i = 0; i < data.size(); i++) {
        f++;
        h[f] = i;
        up(h, f, curs, data);
    }

    while (f > 0) {
        int row_id = h[1];
        out.push_back(data[row_id][curs[row_id]]);
        h[1] = h[f];
        f--;
        down(h, f, curs, data);

        if (curs[row_id] < data[row_id].size() - 1) {
            curs[row_id] += 1;
            f++;
            h[f] = row_id;
            up(h, f, curs, data);
        }
    }
}

void check(const std::vector<int> &vec) {
    int a = 0, b = 0;
    for (int i = 0; i < vec.size(); i++) {
        int n = vec[i];
        if (i > 0 && vec[i] < vec[i - 1]) {
            std::cout << "wrong" << std::endl;
            return;
        }
        a += n;
        a %= 7777771;
        b += n;
        b %= 99991;
    }
    if (a == check_a && b == check_b) std::cout << "correct" << std::endl;
}

int main() {
    int M, N;
    std::cin >> M >> N;

    std::vector<std::vector<int>> data(M, std::vector<int>(N));

    check_a = 0;
    check_b = 0;
    for (int i  = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> data[i][j];
            check_a += data[i][j];
            check_a %= 7777771;
            check_b += data[i][j];
            check_b %= 99991;
        }
    }

    std::vector<int> ans;
    auto start = std::chrono::system_clock::now();
    merge_sort(data, ans);
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "merge time spent: " << double(duration.count()) << std::endl;
    check(ans);

    start = std::chrono::system_clock::now();
    std::vector<int> A;
    merge_sort_two(data[0], data[1], A);
    for (int i = 2; i < M; i++) {
        std::vector<int> B;
        merge_sort_two(A, data[i], B);
        A = B;
    }
    end = std::chrono::system_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "merge two time spent: " << double(duration.count()) << std::endl;
    check(A);

    return 0;
}
