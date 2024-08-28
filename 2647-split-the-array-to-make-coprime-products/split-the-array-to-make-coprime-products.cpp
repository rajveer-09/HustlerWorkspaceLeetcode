class Solution {
public:
    void factorFreq(int x, unordered_map<int, int> &mp) {
        for (int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                mp[i]++;
                x /= i;
            }
        }
        if (x > 1) {
            mp[x]++;
        }
    }

    int findValidSplit(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        unordered_map<int, int> global;
        vector<unordered_map<int, int>> factors(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            factorFreq(nums[i], factors[i]);
            for (auto& p : factors[i]) {
                global[p.first] += p.second;
            }
        }

        unordered_map<int, int> left;
        unordered_map<int, int> active;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (auto& p : factors[i]) {
                left[p.first] += p.second;
                global[p.first] -= p.second;
                if (global[p.first] == 0) {
                    global.erase(p.first);
                } else {
                    active[p.first] = 1;
                }
            }

            bool valid = true;
            for (auto& a : active) {
                if (global.count(a.first)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                return i;
            }
        }

        return -1;
    }
};