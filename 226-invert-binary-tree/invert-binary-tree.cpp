class Solution {
public:
    // we need to reach to every node and swap its righ
    // and left pointers...be it any way we just have to reach & change
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();

            swap(node->left, node->right);

            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
        }

        return root;
    }
};