class Solution {
public:
    void backtrack(TreeNode* root, vector<int>& path, vector<string>& ans) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right) {
            string s = to_string(path[0]);
            for (int i = 1; i < path.size(); ++i) {
                s += "->" + to_string(path[i]);
            }
            ans.push_back(s);
        }

        backtrack(root->left, path, ans);
        backtrack(root->right, path, ans);

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;

        backtrack(root, path, ans);
        
        return ans;
    }
};
