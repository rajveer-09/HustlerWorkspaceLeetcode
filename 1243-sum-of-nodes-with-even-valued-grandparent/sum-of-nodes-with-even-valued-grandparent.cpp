class Solution {
public:
    void solve(TreeNode* root, int a, int b, int& sum) {
        if(!root) return;

        if(a % 2 == 0) sum += root->val;

        solve(root->left, b, root->val, sum);
        solve(root->right, b, root->val, sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        solve(root, -1, -1, sum);

        return sum;
    }
};