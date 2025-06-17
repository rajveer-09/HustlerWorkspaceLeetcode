class Solution {
public:
    int mxDmtr = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int lh = dfs(root->left);
        int rh = dfs(root->right);

        mxDmtr = max(mxDmtr, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return mxDmtr;
    }
};
