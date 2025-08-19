class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int p1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int p2 = nums[0] * nums[1] * nums[n - 1];
        
        return max(p1, p2);
    }
};

/*
1. Agr sirf pos hai toh...last ke 3 
2. agr neg b hai toh... ya toh last ke 3 ya start k 2 and last
*/