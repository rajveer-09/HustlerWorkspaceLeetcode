class Solution {
public:
    void dfs(TreeNode* node, int lvl, int& maxLvl, vector<int>& ans){
        if(!node) return;
        if(lvl > maxLvl){
            ans.push_back(node->val);
            maxLvl = lvl;
        }

        dfs(node->right, lvl + 1, maxLvl, ans);
        dfs(node->left, lvl + 1, maxLvl, ans);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxLvl = -1;
        
        dfs(root, 0, maxLvl, ans);

        return ans;
    }
};