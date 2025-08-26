class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mpp;

    RandomizedCollection() {}

    bool insert(int val) {
        bool flg = !mpp.count(val);
        mpp[val].insert(nums.size());
        nums.push_back(val);
        return flg;
    }
    
    bool remove(int val) {
        if (!mpp.count(val)) return false;

        // take one index of val
        int idx = *mpp[val].begin();
        mpp[val].erase(idx);

        int lastVal = nums.back();
        nums[idx] = lastVal;

        mpp[lastVal].insert(idx);

        // update lastVal indices in mpp
        mpp[lastVal].erase(nums.size() - 1);
        // if (idx < nums.size() - 1) {
        //     // insert but only if idx was not already the last element.
        //     mpp[lastVal].insert(idx);
        // }

        nums.pop_back();
        if (mpp[val].empty()) mpp.erase(val);

        return true;
    }
    
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};