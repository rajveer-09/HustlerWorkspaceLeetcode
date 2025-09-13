class Solution {
public:
    int ans;
    void solve(TreeNode* root, long long sum, int tsum, unordered_map<long long, int>& mpp){
        if(!root) return;

        sum += root->val;

        if(sum == tsum) ans++;
        
        if(mpp.count(sum - tsum)) {
            ans += mpp[sum - tsum];
        }

        mpp[sum]++;

        solve(root->left, sum, tsum, mpp);
        solve(root->right, sum, tsum, mpp);

        mpp[sum]--;
    }

    int pathSum(TreeNode* root, int tsum) {
        ans = 0;

        unordered_map<long long, int> mpp;

        solve(root, 0, tsum, mpp);

        return ans;
    }
};