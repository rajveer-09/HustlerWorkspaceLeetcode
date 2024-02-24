class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0);
        int st = 0, en = n;
        for (int i = 0; i < n; i++) {
            ans[st++] = nums[i];
            ans[st++] = nums[en++];
        }
        return ans;
    }
};