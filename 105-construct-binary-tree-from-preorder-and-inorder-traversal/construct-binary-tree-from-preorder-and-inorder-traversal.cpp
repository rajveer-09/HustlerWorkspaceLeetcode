class Solution {
public:
    int findIdx(vector<int>& inorder, int st, int ed, int& node){
        for(int i = st; i <= ed; i++){
            if(inorder[i] == node){
                return i;
            }
        }
        return -1;
    }
// pre order aur inorder se root banao
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int st, int ed){
        if(idx >= preorder.size()) return NULL;
        if(st > ed) return NULL;

        TreeNode* root = new TreeNode(preorder[idx]);
        int idxx = findIdx(inorder, st, ed, root->val);

        root->left = build(preorder, inorder, ++idx, st, idxx - 1);
        // left part jab complete build ho chuka hoga..aur ham ++idx ke saath jayenge 
        // to vo build nahi hoga...usi idx se ham right side build krnege 
        root->right = build(preorder, inorder, idx, idxx + 1, ed);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;

        TreeNode* root = build(preorder, inorder, idx, 0, n - 1);

        return root;
    }
};