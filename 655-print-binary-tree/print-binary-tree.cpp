class Solution {
public:
    int getHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    void fill(vector<vector<string>>& res, TreeNode* node, int r, int l, int ri) {
        if (!node) {
            return;
        }
        int mid = (l + ri) / 2;

        res[r][mid] = to_string(node->val);
        
        fill(res, node->left, r + 1, l, mid - 1);
        fill(res, node->right, r + 1, mid + 1, ri);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int w = pow(2, h) - 1;

        vector<vector<string>> res(h, vector<string>(w, ""));
        fill(res, root, 0, 0, w - 1);
        return res;
    }
};