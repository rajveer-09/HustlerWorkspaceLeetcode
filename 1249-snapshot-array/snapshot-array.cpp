class SnapshotArray {
private:
    vector<map<int, int>> history;
    int snap_id_counter;

public:
    SnapshotArray(int length) {
        history.resize(length);
        for(int i = 0; i < length; ++i) {
            history[i][0] = 0;
        }
        snap_id_counter = 0;
    }
    
    void set(int index, int val) {
        history[index][snap_id_counter] = val;
    }
    
    int snap() {
        return snap_id_counter++;
    }
    
    int get(int index, int snap_id) {
        auto it = history[index].upper_bound(snap_id);
        --it;
        return it->second;
    }
};