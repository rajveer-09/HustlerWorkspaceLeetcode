class Solution {
public:
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int& i1, int& i2){
        TreeNode* root = new TreeNode(preorder[i1++]);

        // Build left if subtree not closed yet
        if (root->val != postorder[i2]){
            root->left = construct(preorder, postorder, i1, i2);
        }

        // Build right if subtree not closed yet
        if (root->val != postorder[i2]){
            root->right = construct(preorder, postorder, i1, i2);
        }

        // Now this node is closed in postorder
        i2++;
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int i1 = 0, i2 = 0;
        return construct(preorder, postorder, i1, i2);
    }
};
