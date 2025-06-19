/*
class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode* curr =root;

        while(curr){
            if(curr->left){
                TreeNode* temp = curr->left;

                while(temp->right != NULL){
                    temp = temp->right;
                }

                temp->right = curr->right;
                curr->right = curr->left;
                
                curr->left = NULL;
            }
            
            curr = curr->right;
        }

    }
};