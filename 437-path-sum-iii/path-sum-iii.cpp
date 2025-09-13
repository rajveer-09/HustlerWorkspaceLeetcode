class Solution {
    int total = 0;
    
    void findBase(TreeNode* root, int target) {
        if (!root) return;
        find(root, target, 0LL);
        
        findBase(root->left, target);
        findBase(root->right, target);
    }
    
    void find(TreeNode* root, int target, long long curr) {
        if (!root) return;
        curr += root->val;

        if (curr == target) total++;

        find(root->left, target, curr);
        find(root->right, target, curr);
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        total = 0;

        findBase(root, targetSum);

        return total;
    }
};
