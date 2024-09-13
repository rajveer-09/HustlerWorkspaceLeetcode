class Solution{
public:
    void solve(TreeNode *root, int targetSum, vector<vector<int>> &path,vector<int> ans, int sum){
        if (root == NULL)
        {
            return;
        }
        sum += root->val;
        ans.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (sum == targetSum)
            {
                path.push_back(ans);
            }
            return;
        }
        solve(root->left, targetSum, path, ans, sum);
        solve(root->right, targetSum, path, ans, sum);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum){
        ios_base::sync_with_stdio(false);
        int sum = 0;
        vector<int> ans;
        vector<vector<int>> path;
        solve(root, targetSum, path, ans, sum);
        return path;
    }
};