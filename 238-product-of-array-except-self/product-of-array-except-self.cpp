class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n); 
        vector<int> r(n);
        vector<int> res(n);

        int lp = 1;
        for (int i = 0; i < n; ++i) {
            l[i] = lp;
            lp *= nums[i];
        }
        int rp = 1;
        for (int i = n - 1; i >= 0; --i) {
            r[i] = rp;
            rp *= nums[i];
        }
        for (int i = 0; i < n; ++i) {
            res[i] = l[i] * r[i];
        }
        return res;
    }
};