class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {

        ios::sync_with_stdio(false); cin.tie(nullptr);
        
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num)) {
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};