class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> arr(nums.begin(), nums.end());
        for(int num : nums){
            arr.push_back(num);
        }

        int tt = accumulate(nums.begin(), nums.end(), 0);

        int cnt = 0;
        int st = 0;
        int ans = 0;

        for(int i = 0; i < arr.size(); i++){
            cnt += arr[i];

            if(i - st + 1 == tt){
                ans = max(ans, cnt);

                cnt -= arr[st];
                st++;
            }
        }

        return tt - ans;
    }
};