class RandomizedSet {
private:
    unordered_map<int, int> pos;
    vector<int> vals;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (pos.count(val)) {
            return false;
        }
        vals.push_back(val);
        pos[val] = vals.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!pos.count(val)) {
            return false;
        }
        int last = vals.back();
        int idx = pos[val];

        vals[idx] = last;
        pos[last] = idx;

        vals.pop_back();
        pos.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */