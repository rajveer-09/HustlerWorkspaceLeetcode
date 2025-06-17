class Solution {
public:
    pair<bool, int> check(TreeNode* root) {
        if (!root) return {true, 0};

        auto left = check(root->left);
        auto right = check(root->right);

        bool balanced = left.first && right.first && abs(left.second - right.second) <= 1;
        int height = 1 + max(left.second, right.second);

        return {balanced, height};
    }

    bool isBalanced(TreeNode* root) {
        return check(root).first;
    }
};
