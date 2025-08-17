class BSTIterator {
public:
    vector<int> values;
    int index;

    void inorderTraversal(TreeNode* node) {
        if (!node) return;
        inorderTraversal(node->left);

        values.push_back(node->val);
        
        inorderTraversal(node->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
        index = -1;
    }
    
    bool hasNext() {
        return index + 1 < values.size();
    }
    
    int next() {
        return values[++index];
    }

};