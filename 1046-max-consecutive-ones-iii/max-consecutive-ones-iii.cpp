class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //your code goes here
        int cnt = 0;
        int ans = 0;
        int st = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) cnt++;

            if(cnt > k){
                if(nums[st] == 0){
                    cnt--;
                }

                st++;
            }

            ans = max(ans, i - st + 1);
        }

        return ans;
    }
};