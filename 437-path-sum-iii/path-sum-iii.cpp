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

/*
<- BRUTE-FORCE ->

class Solution {
    int total = 0;
    
    void findBase(TreeNode* root, int target) {
        if (!root) return;
        find(root, target, 0LL);

        findBase(root->left, target);
        findBase(root->right, target);
    }
    
    void find(TreeNode* root, int target, long long curr) {
        if (!root) return;
        curr += root->val;

        if (curr == target) total++;

        find(root->left, target, curr);
        find(root->right, target, curr);
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        total = 0;

        findBase(root, targetSum);

        return total;
    }
};

*/