class Solution {
public:
    int moves = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);

        moves += abs(left) + abs(right);  
        return node->val + left + right - 1;  // excess coins to pass up
    }
    
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
