class Solution {
public:
    void inorder(TreeNode* root, int& k, int& ans) {
        if (!root || k <= 0) return;

        inorder(root->left, k, ans);

        if (k > 0) {
            k--;

            if (k == 0) {
                ans = root->val;
                return;
            }

            inorder(root->right, k, ans);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        
        return ans;
    }
};