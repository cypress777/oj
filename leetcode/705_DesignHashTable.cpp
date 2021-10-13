#include<vector>
#include<set>

using namespace std;


class MyHashSet {
private:
    vector<set<int>> _buckets;

    int _bucket_id(int n) { return n / 100; }
    int _bucket_pos(int n) {return n % 100; }
public:
    MyHashSet() {
        _buckets = vector<set<int>>(10001, set<int>{});
    }
    
    void add(int key) {
        _buckets[_bucket_id(key)].insert(_bucket_pos(key));
    }
    
    void remove(int key) {
        int bid = _bucket_id(key);
        int bpos = _bucket_pos(key);
        if (_buckets[bid].find(bpos) != _buckets[bid].end()) _buckets[bid].erase(bpos);
    }
    
    bool contains(int key) {
        int bid = _bucket_id(key);
        int bpos = _bucket_pos(key);
        return _buckets[bid].find(bpos) != _buckets[bid].end();
    }
};