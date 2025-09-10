class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);

        return 1 + max(ld, rd);
    }
};