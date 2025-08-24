class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> rem_counts;

        for (int x : arr) {
            rem_counts[((x % k) + k) % k]++;
        }

        for (auto const& [rem, count] : rem_counts) {
            if (rem == 0 || rem * 2 == k) {
                if (count % 2 != 0) {
                    return false;
                }
            } 
            else {
                if (rem_counts[rem] != rem_counts[k - rem]) {
                    return false;
                }
            }
        }

        return true;
    }
};