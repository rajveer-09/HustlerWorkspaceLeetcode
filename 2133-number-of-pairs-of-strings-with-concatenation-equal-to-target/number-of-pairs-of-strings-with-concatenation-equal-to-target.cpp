class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> freq;
        for (const string& s : nums) {
            freq[s]++;
        }

        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (target.size() > nums[i].size()) {
                if (target.substr(0, nums[i].size()) == nums[i]) {
                    string complement = target.substr(nums[i].size());
                    
                    if (complement == nums[i]) {
                        count += freq[complement] - 1;
                    } else {
                        count += freq[complement];
                    }
                }
            }
        }
        return count;
    }
};