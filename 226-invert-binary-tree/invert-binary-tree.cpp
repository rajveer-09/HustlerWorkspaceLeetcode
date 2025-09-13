class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            
            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);

            swap(node->left, node->right);
        }
        return root;
    }
};