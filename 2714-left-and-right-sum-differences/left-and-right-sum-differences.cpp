class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int left_sum=0;
        int right_sum=0;
        for(int i=0;i<nums.size();i++){
            right_sum=sum-nums[i]-left_sum;
            ans.push_back(abs(right_sum-left_sum));
            left_sum+=nums[i];
        }
        return ans;
    }
};