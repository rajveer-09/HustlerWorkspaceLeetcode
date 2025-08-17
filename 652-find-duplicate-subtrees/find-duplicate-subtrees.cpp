class Solution {
private:
    unordered_map<string, int> subtreeCount;
    vector<TreeNode*> result;

    string serialize(TreeNode* node) {
        if (!node) {
            return "#";
        }

        string left = serialize(node->left);
        string right = serialize(node->right);

        string s = to_string(node->val) + "," + left + "," + right;
        
        if (subtreeCount[s] == 1) {
            result.push_back(node);
        }

        subtreeCount[s]++;

        return s;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        
        return result;
    }
};