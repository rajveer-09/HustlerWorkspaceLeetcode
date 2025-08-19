class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum = 0;
        mpp[0] = 1;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            int rem = (sum % k + k) % k;

            if(mpp.count(rem)){
                ans += mpp[rem];
            }

            mpp[rem]++;
        }

        return ans;
    }
};