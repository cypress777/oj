int MAX_SIZE = 20010;

struct Wall {
    int pos;
    int height;
    bool is_left;
    bool is_valid;
    Wall *other;
    
    Wall(int p, int h, int is_l) {
        pos = p;
        height = h;
        is_left = is_l;
        is_valid = true;
    }
    
    void set_other(Wall *o) {
        other = o;
    }
};

bool comp(Wall *a, Wall *b) {
    if (a->pos == b->pos) {
        if (!a->is_left && b->is_left) {
            return true;
        } else if (a->is_left && !b->is_left) {
            return false;
        } else {
            return (a->height > b->height);
        }
    } else {
        return (a->pos < b->pos);
    }
}

struct Heap {
    vector<Wall *> array;
    int cap;
    int size;
    
    Heap() {
        cap = MAX_SIZE;
        size = 0;
        array = vector<Wall *>(cap, nullptr);
    }
    
    void swap(int i, int j) {
        Wall *tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    
    int parent(int i) { return (i - 1) / 2; }
    
    int left(int i) { return 2 * i + 1; }
    
    int right(int i) { return 2 * i + 2; }
    
    void up(int i) {
        while (i > 0 && comp(array[i], array[parent(i)])) {
            swap(i, parent(i));
            i = parent(i);
        }
    }
    
    void down(int i) {
        while (i < size) {
            int l = left(i), r = right(i);

            int small = i;
            if (l < size && comp(array[l], array[i])) {
                small = l;
            }
            if (r < size && comp(array[r], array[small])) {
                small = r;
            }
            if (small != i)  {
                swap(i, small);
                i = small;
            } else {
                break;
            }
        }
    }
    
    void insert_key(Wall *key) {
        size++;
        int i = size - 1;
        array[i] = key;

        up(i);
    }

    void delete_key(int i) {
        array[i] = array[size - 1];
        size--;

        if (i < size - 1) down(i);
    }
    
    Wall * get_key(int i) { return (i <= size - 1 ? array[i] : nullptr); }
    
    int get_size() { return size; }
};

bool h_comp(Wall *a, Wall *b) {
    if (a->height == b->height) {
        return (a->pos < b->pos);
    } else {
        return (a->height < b->height);
    }
}

class Solution {
public:
    vector<Wall *> lwalls;
    Heap walls;
    vector<vector<int>> result;

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.size() == 0) return result;

        for (auto building : buildings) {
            Wall *lnode = new Wall(building[0], building[2], true);
            Wall *rnode = new Wall(building[1], building[2], false);
            lnode->set_other(rnode);
            rnode->set_other(lnode);
            lwalls.push_back(lnode);
        }
        
        sort(lwalls.begin(), lwalls.end(), h_comp);
        Wall *last = lwalls[0];
        for (int i = 1; i < lwalls.size(); i++) {
            Wall *cur = lwalls[i];

            if (cur->height == last->height && cur->pos <= last->other->pos) {
                last->other->pos = max(cur->other->pos, last->other->pos);
            } else {
                walls.insert_key(last);
                walls.insert_key(last->other);
                last = cur;
            }
        }
        walls.insert_key(last);
        walls.insert_key(last->other);
        
        vector<Wall *> stack(MAX_SIZE, nullptr);
        int top = -1;
        
        while (walls.get_size() > 0) {
            Wall *cur_wall = walls.get_key(0);
            walls.delete_key(0);
            if (!cur_wall->is_valid) continue;
            
            Wall *top_wall = (top >= 0 ? stack[top] : nullptr);
            
            if (cur_wall->is_left) {
                if (top_wall == nullptr || top_wall->height < cur_wall->height) {
                    top++;
                    stack[top] = cur_wall;
                    result.push_back({cur_wall->pos, cur_wall->height});
                } else {
                    if (cur_wall->other->pos <= top_wall->other->pos) {
                        cur_wall->other->is_valid = false;
                    } else {
                        cur_wall->pos = top_wall->other->pos;
                        walls.insert_key(cur_wall);
                    }
                }
            } else {
                if (cur_wall->other == stack[top]) {
                    top--;
                    while (top >= 0) {
                        if (stack[top]->is_valid) break;
                        top--;
                    }

                    Wall *next_wall = walls.get_key(0);
                    while(next_wall != nullptr) {
                        if (next_wall->is_valid) break;
                        
                        walls.delete_key(0);
                        next_wall = walls.get_key(0);
                    }
                    
                    int cur_top_height = top < 0 ? 0 : stack[top]->height;
                    if (next_wall == nullptr || next_wall->pos > cur_wall->pos || next_wall->height < cur_top_height) {
                        result.push_back({cur_wall->pos, cur_top_height});
                    }
                } else {
                    cur_wall->other->is_valid = false;
                }
            }
        }
        
        return result;
    }
};
