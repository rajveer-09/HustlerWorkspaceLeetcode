class Solution {
public:
    unordered_map<int, int> mpp;
    // pre order aur inorder se root banao
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int st, int ed){
        if(idx >= preorder.size()) return NULL;
        if(st > ed) return NULL;

        TreeNode* root = new TreeNode(preorder[idx++]);
        int idxx = mpp[root->val];

        root->left = build(preorder, inorder, idx, st, idxx - 1);
        
        root->right = build(preorder, inorder, idx, idxx + 1, ed);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        for(int i = 0; i < n; i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = build(preorder, inorder, idx, 0, n - 1);

        return root;
    }
};