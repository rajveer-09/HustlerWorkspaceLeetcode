class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(), nums.end());
        int d1 = min(nums[n-4]-nums[0], nums[n-3]-nums[1]);
        int d2 = min(nums[n-1]-nums[3], nums[n-2]-nums[2]);


        return min(d1, d2);
    }
};