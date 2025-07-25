class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int tt = 0;

        for(int i = 0; i < n; i++){
            tt += abs(nums[i] - nums[n / 2]);
        }

        return tt;
    }
};