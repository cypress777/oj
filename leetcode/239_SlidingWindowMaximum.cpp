class Solution {
public:
    struct Heap {
        vector<int> heap;
        vector<int> index;
        int cap;
        int size;
        vector<int> pos;

        Heap(int heap_cap, int nums_size) {
            cap = heap_cap;
            size = 0;
            heap = vector<int>(cap, 0);
            index = vector<int>(cap, 0);
            pos = vector<int>(nums_size, -1);
        }

        int parent(int i) { return (i - 1) / 2; }

        int left(int i) { return 2 * i + 1; }

        int right(int i) { return 2 * i + 2; };

        void swap(int i, int j) {
            int tmp = heap[i];
            heap[i] = heap[j];
            heap[j] = tmp;
            
            tmp = pos[index[i]];
            pos[index[i]] = pos[index[j]];
            pos[index[j]] = tmp;

            tmp = index[i];
            index[i] = index[j];
            index[j] = tmp;
        }

        void up(int i) {
            while (i > 0 && heap[parent(i)] < heap[i]) {
                swap(i, parent(i));
                i = parent(i);
            }
        }

        void down(int i) {
            while (i < size - 1) {
                int l = left(i), r = right(i);

                int mx = i;
                if (l < size && heap[l] > heap[i]) mx = l;
                if (r < size && heap[r] > heap[mx]) mx = r;

                if (mx == i) break;

                swap(i, mx);
                i = mx;
            }
        }

        void delete_key(int i) {
            if (i >= size) return;
            swap(i, size - 1);
            size--;
            down(i);
            up(i);
        }
        
        void insert_key(int val, int id) {
            size++;
            heap[size - 1] = val;
            index[size - 1] = id;
            pos[id] = size - 1;
            
            up(size - 1);
        }

        int get_key(int i) { return heap[i]; }
        
        int get_size() { return size; }
        
        int get_pos_by_index(int id) { return pos[id]; }
    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        Heap h = Heap(k, nums.size());

        for (int i = 0; i < nums.size(); i++) {
            h.insert_key(nums[i], i);
            
            if (h.get_size() < k) continue;
            
            int mx = h.get_key(0);
            result.push_back(mx);
            
            int del_id = h.get_pos_by_index(i - k + 1);
            h.delete_key(del_id);
        }
        
        return result;
    }
};

class SolutionA {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        vector<int> deque(nums.size() + 10, 0);
        int p = 0, q = -1;

        for (int i = 0; i < nums.size(); i++) {
            int nq = q;
            for (int j = q; j >= p; j--) {
                if (nums[deque[j]] <= nums[i]) nq--;
                else break;
            }
            q = nq + 1;
            deque[q] = i;

            int np = p;
            for (int j = p; j <= q; j++) {
                if (i - deque[j] + 1 > k) np++;
                else break;
            }
            p = np;

            if (i >= k - 1) result.push_back(nums[deque[p]]);
        }

        return result;
    }
};
