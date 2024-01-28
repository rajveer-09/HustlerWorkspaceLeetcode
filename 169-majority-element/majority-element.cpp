class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (ans == nums[i])
                count++;
            else
                count--;
            if (count == 0) {
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};