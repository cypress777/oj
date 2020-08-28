class CustomStack {
public:
    int top = -1;
    int max_size = 0;
    vector<int> stack;
    
    CustomStack(int maxSize) {
        max_size = maxSize;
        stack = vector<int>(maxSize);
    }
    
    void push(int x) {
        if (top < max_size - 1) {
            top++;
            stack[top] = x;
        }
    }
    
    int pop() {
        if (top >= 0) {
            int val = stack[top];
            top--;
            return val;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, max_size); i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
