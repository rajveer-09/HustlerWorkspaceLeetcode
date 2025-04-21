class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void addParent(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            parent[root->left] = root;
            addParent(root->left);
        }

        if (root->right) {
            parent[root->right] = root;
            addParent(root->right);
        }
    }

    TreeNode* findNode(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;

        TreeNode* left = findNode(root->left, val);
        if (left) return left;

        return findNode(root->right, val);
    }

    int amountOfTime(TreeNode* root, int start) {
        addParent(root);
        
        TreeNode* target = findNode(root, start);

        queue<TreeNode*> que;
        que.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int time = -1;

        while (!que.empty()) {
            int size = que.size();
            time++;

            while (size--) {
                TreeNode* curr = que.front();
                que.pop();

                if (curr->left && !visited.count(curr->left)) {
                    que.push(curr->left);
                    visited.insert(curr->left);
                }

                if (curr->right && !visited.count(curr->right)) {
                    que.push(curr->right);
                    visited.insert(curr->right);
                }

                if (parent.count(curr) && !visited.count(parent[curr])) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
        }

        return time;
    }
};