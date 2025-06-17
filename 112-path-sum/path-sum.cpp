class Solution {
public:
    bool solve(TreeNode* root, int tg){
        if(!root) return false;

        if(root->val == tg && !root->left && !root->right) return true;

        bool l = solve(root->left, tg - root->val);
        bool r = solve(root->right, tg - root->val);

        return l || r;
    } 
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};