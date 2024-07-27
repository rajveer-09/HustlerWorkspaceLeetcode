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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool isLeftToRight = true;
        while (!dq.empty()) {
            vector<int> currLevel;
            int sz = dq.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = dq.front();
                dq.pop_front();
                if (isLeftToRight) currLevel.push_back(node->val);
                else currLevel.insert(currLevel.begin(), node->val);
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            }
            ans.push_back(currLevel);
            isLeftToRight = !isLeftToRight;
        }
        return ans;
    }
};
