class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int flipCount = 0; // even, odd

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && !flipCount) {
                ans++;
                flipCount ^= 1;
            }
            else if(nums[i] == 1 && flipCount){
                ans++;
                flipCount ^= 1;
            }
        }

        return ans;
    }
};