class Solution {
private:
    int solve(vector<int>& nums, int k) {
        int l = 0, r = 0, count = 0, sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > k && l < r) {
                sum -= nums[l];
                l++;
            }
            if (sum <= k)
                count += r - l + 1;
            r++;
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};