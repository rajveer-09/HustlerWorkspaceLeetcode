class Solution {
public:
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int& i1, int& i2){
        if(i1 == preorder.size()) return NULL;

        TreeNode* root = new TreeNode(preorder[i1++]);
        cout<<i2<<" "<<root->val<<endl;
        if(root->val == postorder[i2]){
            i2++;
            cout<<i2<<"->"<<root->val<<endl;
            return root;
        }

        root->left = construct(preorder, postorder, i1, i2);
        if(root->val == postorder[i2]){
            i2++;
            cout<<i2<<"->"<<root->val<<endl;
            return root;
        }
        root->right = construct(preorder, postorder, i1, i2);

        i2++;

        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int i1 = 0, i2 = 0;
        return construct(preorder, postorder, i1, i2);
    }
};