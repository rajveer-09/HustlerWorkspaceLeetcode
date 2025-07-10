class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int st = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i - st + 1 == 3){
                if(nums[st] == 0){
                    cout<<i<<" ";
                    ans++;
                    nums[i] = 1 - nums[i];
                    nums[i - 1] = 1 - nums[i - 1];

                }

                st++;
            }
        }

        if(nums[n - 1] == 0 || nums[n - 2] == 0) return -1;

        return ans;
    }
};