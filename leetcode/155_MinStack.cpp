class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        p = -1;
        min_p = -1;
    }

    void push(int x) {
        // cout << "push " << x << endl;
        p++;
        if (p == stack.size()) stack.push_back(x);
        else stack[p] = x;

        if (min_p == -1 || x <= min_stack[min_p]) {
            min_p++;
            if (min_p == min_stack.size()) min_stack.push_back(x);
            else min_stack[min_p] = x;
        }
    }

    void pop() {
        // cout << "pop" << endl;
        if (p < 0) return;

        if (stack[p] == min_stack[min_p]) min_p--;
        p--;
    }

    int top() {
        // cout << "top" << endl;
        return stack[p];
    }

    int getMin() {
        // cout << "get min " << min_stack[min_p] << endl;
        return min_stack[min_p];
    }

private:
    vector<int> stack;
    int p;
    vector<int> min_stack;
    int min_p;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
