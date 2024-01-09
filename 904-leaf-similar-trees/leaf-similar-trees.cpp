/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

         vector<int> s1 = getSequence(root1);
        vector<int> s2 = getSequence(root2);
        if (s1.size() != s2.size()) {
            return false;
        }
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }

private:
    vector<int> getSequence(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(root->val);
            return;
        }
        dfs(root->left, result);
        dfs(root->right, result);
        
    }
};