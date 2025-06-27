class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int solve(TreeNode* root) {
        if (!root) return 0;

        if (dp.count(root)) return dp[root];

        int take = root->val;
        if (root->left) {
            take += solve(root->left->left);
            take += solve(root->left->right);
        }
        if (root->right) {
            take += solve(root->right->left);
            take += solve(root->right->right);
        }

        int notTake = solve(root->left) + solve(root->right);

        return dp[root] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        return solve(root);
    }
};
