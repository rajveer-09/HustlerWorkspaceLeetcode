class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long min, long max) {
        if (node == nullptr) return true;

        if (node->val <= min || node->val >= max) return false;

        return validate(node->left, min, node->val) &&
               validate(node->right, node->val, max);
    }
};