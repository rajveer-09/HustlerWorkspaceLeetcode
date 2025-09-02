class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {nullptr, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second > right.second) return {left.first, left.second + 1};
        if (right.second > left.second) return {right.first, right.second + 1};

        // If depths are equal, current node is LCA
        return {root, left.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
