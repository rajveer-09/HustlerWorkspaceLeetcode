class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> same(2, 0), diff(2, 0);
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int curRem = nums[i] % 2;
            same[curRem] = same[curRem] + 1;
            diff[curRem] = max(diff[curRem], 1 + diff[1 ^ curRem]);
        }

        return max({same[0], same[1], diff[0], diff[1]});
    }
};