class MyHashMap {
private:
    vector<list<pair<int, int>>> hash_table;
    int size = 1000;

    int hash(int key) {
        return key % size;
    }
public:
    MyHashMap() {
        hash_table.resize(size);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        for (auto& pair : hash_table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        hash_table[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        for (const auto& pair : hash_table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        //  list in C++ is a doubly linked list. 
        auto& list = hash_table[index];
        for (auto& it : hash_table[index]) {
            if (it.first == key) {
                list.remove(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */