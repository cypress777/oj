#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std::chrono;

int check_a;
int check_b;

void print_vector(const std::vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) std::cout << v[i] << " ";
    std::cout << v[v.size() - 1] << std::endl;
}

void insertion_sort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        int min_n = nums[i];
        int min_id = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < min_n) {
                min_n = nums[j];
                min_id = j;
            }
        }
        nums[min_id] = nums[i];
        nums[i] = min_n;
    }
}

void bubble_sort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j < nums.size() - i; j++) {
            if (nums[j] < nums[j - 1]) {
                int tmp = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

void radix_sort(std::vector<int> &nums) {
    int max_n = nums[0];
    for (int n : nums) if (n > max_n) max_n = n;
    int k = 0;
    while (max_n > 0) k++, max_n /= 10;

    for (int i = 0; i < k; i++) {
        std::vector<std::vector<int>> rad(10, std::vector<int>());
        int base = 1;
        int p = i;
        while (p > 0) base *= 10, p--;
        for (int j = 0; j < nums.size(); j++) {
            rad[nums[j] / base % 10].push_back(nums[j]);
        }

        int id = 0;
        for (int j = 0; j < 10; j++) {
            for (int n : rad[j]) nums[id] = n, id++;
        }
    }
}

void quick_sort(std::vector<int> &nums, int start, int end) {
    int a, b, c;
    int len = end - start + 1;
    a = random() % len + start;
    b = random() % len + start;
    c = random() % len + start;
    std::vector<int> tmp_nums({nums[a], nums[b], nums[c]});
    insertion_sort(tmp_nums);
    int mid = tmp_nums[1];
    int mid_id;
    if (nums[a] == mid) mid_id = a;
    if (nums[b] == mid) mid_id = b;
    if (nums[c] == mid) mid_id = c;

    nums[mid_id] = nums[start];
    nums[start] = mid;

    int r = start + 1;
    int f = end;
    while (r <= f) {
        while (nums[r] <= mid && r <= end) r++;
        while (nums[f] > mid && f >= start + 1) f--;
        if (r > f) break;
        int tmp = nums[r];
        nums[r] = nums[f];
        nums[f] = tmp;
    }

    int tmp = nums[f];
    nums[f] = mid;
    nums[start] = tmp;

    if (f - 1 > start) quick_sort(nums, start, f - 1);
    if (end > r) quick_sort(nums, r, end);
}

void up(std::vector<int> &h, int f, int id) {
    while (id > 1) {
        if (h[id] < h[id / 2]) {
            int tmp = h[id / 2];
            h[id / 2] = h[id];
            h[id] = tmp;
            id /= 2;
        } else {
            break;
        }
    }
}

void down(std::vector<int> &h, int f, int id) {
    while (id < f) {
        int nid = id;
        if (id * 2 <= f && h[id * 2] < h[id]) nid = id * 2;
        if (id * 2 + 1 <= f && h[id * 2 + 1] < h[nid]) nid = id * 2 + 1;
        if (nid != id) {
            int tmp = h[nid];
            h[nid] = h[id];
            h[id] = tmp;
            id = nid;
        } else {
            break;
        }
    }
}

void heap_sort(std::vector<int> &nums) {
    int f = 0;
    std::vector<int> heap(nums.size());
    for (int n : nums) {
        f++;
        heap[f] = n;
        up(heap, f, f);
    }

    for (int i = 0; i < nums.size(); i++) {
        nums[i] = heap[1];
        heap[1] = heap[f];
        f--;
        down(heap, f, 1);
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
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) std::cin >> vec[i];

    check_a = 0;
    check_b = 0;
    for (int n : vec) {
        check_a += n;
        check_a %= 7777771;
        check_b += n;
        check_b %= 99991;
    }

//    auto vec1 = vec;
    auto start = system_clock::now();
//    insertion_sort(vec1);
    auto end = system_clock::now();
//    check(vec1);
    auto duration = duration_cast<microseconds>(end - start);
//    std::cout << "insertion time spent: " << double(duration.count()) << std::endl;
//
//    auto vec2 = vec;
//    start = system_clock::now();
//    bubble_sort(vec2);
//    end = system_clock::now();
//    check(vec2);
//    duration = duration_cast<microseconds>(end - start);
//    std::cout << "bubble time spent: " << double(duration.count()) << std::endl;

    auto vec3 = vec;
    start = system_clock::now();
    radix_sort(vec3);
    end = system_clock::now();
    check(vec3);
    duration = duration_cast<microseconds>(end - start);
    std::cout << "radix time spent: " << double(duration.count()) << std::endl;

    auto vec4 = vec;
    start = system_clock::now();
    quick_sort(vec4, 0, vec.size() - 1);
    end = system_clock::now();
    check(vec4);
    duration = duration_cast<microseconds>(end - start);
    std::cout << "quick time spent: " << double(duration.count()) << std::endl;

    auto vec5 = vec;
    start = system_clock::now();
    heap_sort(vec5);
    end = system_clock::now();
    check(vec5);
    duration = duration_cast<microseconds>(end - start);
    std::cout << "heap time spent: " << double(duration.count()) << std::endl;


    auto vec6 = vec;
    start = system_clock::now();
    std::sort(vec6.begin(), vec6.end());
    end = system_clock::now();
    check(vec6);
    duration = duration_cast<microseconds>(end - start);
    std::cout << "std time spent: " << double(duration.count()) << std::endl;
    return 0;
}