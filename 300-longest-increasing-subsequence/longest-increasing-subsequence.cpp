class Solution {
public:
    int optimalBinarySearch(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else
            {
                // overwrite the previous just big element
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        
        return optimalBinarySearch(nums);
    }
};