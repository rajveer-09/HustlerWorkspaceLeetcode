class Solution {
public:
    unordered_map<int, int> inIndex;

    TreeNode* build(const vector<int>& postorder, int& idx, int st, int ed) {
        if (st > ed) return nullptr;

        TreeNode* root = new TreeNode(postorder[idx]);
        int splitIndex = inIndex[root->val];
        idx--;

        // Important: build right subtree first
        root->right = build(postorder, idx, splitIndex + 1, ed);
        root->left = build(postorder, idx, st, splitIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inIndex[inorder[i]] = i;
        }
        int idx = n - 1; // start from last element in postorder
        return build(postorder, idx, 0, n - 1);
    }
};
