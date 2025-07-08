class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int tt = accumulate(nums.begin(), nums.end(), 0);

        int cnt = 0;
        int st = 0;
        int ans = 0;

        for(int i = 0; i < n * 2; i++){
            cnt += nums[i % n];

            if(i - st + 1 == tt){
                ans = max(ans, cnt);

                cnt -= nums[st % n];
                st++;
            }
        }

        return tt - ans;
    }
};