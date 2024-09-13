class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        ios_base::sync_with_stdio(false);
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        bool leftSum = hasPathSum(root->left, targetSum - root->val);
        bool rightSum = hasPathSum(root->right, targetSum - root->val);

        return leftSum || rightSum;
    }
};
