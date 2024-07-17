
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, TreeNode*> res;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        res[root->val] = root;

        function<void(TreeNode*, TreeNode*, bool)> recursion = [&](TreeNode* parent, TreeNode* cur_node, bool isleft) {
            if (cur_node == nullptr) return;

            recursion(cur_node, cur_node->left, true);
            recursion(cur_node, cur_node->right, false);

            if (to_delete_set.find(cur_node->val) != to_delete_set.end()) {
                if (res.find(cur_node->val) != res.end()) {
                    res.erase(cur_node->val);
                }

                if (parent) {
                    if (isleft) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                }

                if (cur_node->left) {
                    res[cur_node->left->val] = cur_node->left;
                }
                if (cur_node->right) {
                    res[cur_node->right->val] = cur_node->right;
                }
            }
        };

        recursion(nullptr, root, false);
        
        vector<TreeNode*> result;
        for (auto& pair : res) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};