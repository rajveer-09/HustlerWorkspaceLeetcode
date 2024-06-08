class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev = nums[n - 1];
        int current = max(nums[n - 1], nums[n - 2]);
        
        for (int i = n - 3; i >= 0; i--) {
            int temp = prev;
            prev = current;
            current = max(nums[i] + temp, prev);
        }
        
        return current;
    }
};
