class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for(int num : nums) mpp[num]++;

        int ans = 0;

        for(auto[num, freq] : mpp){
            if(freq % k == 0){
                ans += (freq * num);
            }
        }

        return ans;
    }
};