class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        if (res.size() == depth) {
            res.push_back({});
        }

        res[depth].push_back(node->val);
        
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};