#include<queue>
using namespace std;


class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> _que;
    int _k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        
        for (int num : nums) add(num);
    }
    
    int add(int val) {
        if (_que.size() < _k || _que.top() < val) {
            _que.push(val);
        }
        if (_que.size() > _k) _que.pop();
        
        return _que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */