class MyHashSet {
private:
    vector<list<int>> hashSet;
    int size = 1000;
    int hash(int key) {
        return key % size;
    }

public:
    MyHashSet() {
        hashSet.resize(size);
    }
    
    void add(int key) {
        int hashVal = hash(key);
        for(int val : hashSet[hashVal]){
            if(val == key) return;
        }
        hashSet[hashVal].push_back(key);
    }
    
    void remove(int key) {
        int hashVal = hash(key);
        hashSet[hashVal].remove(key);
    }
    
    bool contains(int key) {
        int hashVal = hash(key);
        for(int val : hashSet[hashVal]){
            if(val == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */