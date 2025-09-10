class Solution {
public:
    void dfs(TreeNode* node, int lvl, vector<int>& ans){
        if(!node) return;
        if(lvl >= ans.size()){
            ans.push_back(node->val);
        }

        dfs(node->right, lvl + 1, ans);
        dfs(node->left, lvl + 1, ans);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        dfs(root, 0, ans);

        return ans;
    }
};