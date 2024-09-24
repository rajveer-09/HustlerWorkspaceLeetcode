class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int j = 1;
        int i = 0;
        int ans = 0;
        while (i < nums.size() && j < nums.size()) {
            if (nums[j] - nums[i] == k) {
                ans++;
                j++;
                i++;
                while (j < nums.size() && nums[j] == nums[j - 1]) {
                    j++;
                }
            } else if (nums[j] - nums[i] > k) {
                i++;
                if (j - i == 0) {
                    j++;
                }
            } else {
                j++;
            }
        }
        return ans;
    }
};
