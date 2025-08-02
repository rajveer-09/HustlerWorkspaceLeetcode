class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
    bool dfs(TreeNode* node, ListNode* head) {
        if (!head) return true;
        if (!node) return false;
        
        if (node->val != head->val) return false;

        return dfs(node->left, head->next) || dfs(node->right, head->next);
    }
};
