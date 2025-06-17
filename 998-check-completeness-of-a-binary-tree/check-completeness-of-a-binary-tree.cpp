class Solution {
public:
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool solve(TreeNode* root, int idx, int max){
        if(root == NULL) return true;

        if(idx > max) return false;

        bool l = solve(root->left, 2 * idx, max);
        bool r = solve(root->right, 2 * idx + 1, max);

        return l && r;

    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);

        return solve(root, 1, totalNodes);
    }
};