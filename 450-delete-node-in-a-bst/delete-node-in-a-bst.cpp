class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else { 
            // Node to delete found
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Find inorder successor (min in right subtree)
            TreeNode* succ = root->right;
            while (succ->left) succ = succ->left;
            
            // Replace value & delete successor
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }

        return root;
    }
};