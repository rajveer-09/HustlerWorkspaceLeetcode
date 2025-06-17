class Solution {
public:
    void traverse(TreeNode* root, string s, vector<string>& ans){
        if(!root) return;

        if(s.size() == 0){
            s += to_string(root->val);
        }
        else{
            s += "->";
            s += to_string(root->val);
        }

        if(!root->left && !root->right){
            ans.push_back(s);
        
        }

        traverse(root->left, s, ans);
        traverse(root->right, s, ans);

        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        vector<string> ans;

        traverse(root, s, ans);

        return ans;
    }
};