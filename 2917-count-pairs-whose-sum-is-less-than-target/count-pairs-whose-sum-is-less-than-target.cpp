class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int count = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            if (nums[l] + nums[r] < target) {
                count += (r - l); // valid pairs with nums[l]
                l++;
            } else {
                r--;
            }
        }
        
        return count;
    }
};