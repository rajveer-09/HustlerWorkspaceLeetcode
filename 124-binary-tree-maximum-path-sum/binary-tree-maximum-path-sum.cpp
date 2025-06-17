class Solution {
public:
    int ans = INT_MIN;

    int solve(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        int localMax = root->val + left + right;
        ans = max(ans, localMax);

        // Return one side path to parent kyuki parent ko v apne baap ko return krna hai
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};