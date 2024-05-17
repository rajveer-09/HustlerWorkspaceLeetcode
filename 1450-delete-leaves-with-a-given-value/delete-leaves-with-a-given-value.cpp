#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    static TreeNode* removeLeafNodes(TreeNode* root, int target, TreeNode* parent=NULL) {
        if (!root) return NULL;

        // Recursively remove leaf nodes from left and right subtrees
        root->left = removeLeafNodes(root->left, target, root);
        root->right = removeLeafNodes(root->right, target, root);

        // If current node is a leaf(not root) and its value==target, delete it
        if (!root->left && !root->right && root->val==target) {
            if (parent)  delete root; //the root cannot be deleted
            return NULL;
        }

        return root;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();