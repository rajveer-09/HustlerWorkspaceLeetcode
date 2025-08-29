class Solution {
public:
    vector<int> ans;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return ans;
    }

private:
    // collect all nodes k distance below current node
    void subtreeAdd(TreeNode* node, int dist, int k) {
        if (!node) return;
        if (dist == k) {
            ans.push_back(node->val);
            return;
        }
        subtreeAdd(node->left, dist+1, k);
        subtreeAdd(node->right, dist+1, k);
    }

    // returns distance of target from current node, or -1 if not found
    int dfs(TreeNode* root, TreeNode* target, int k) {
        if (!root) return -1;

        if (root == target) {
            subtreeAdd(root, 0, k); // collect all k distance down
            return 0;
        }

        // check left subtree
        int left = dfs(root->left, target, k);
        if (left != -1) {
            if (left + 1 == k) ans.push_back(root->val); // root is at distance k
            else subtreeAdd(root->right, left+2, k);     // check right subtree
            return left + 1;
        }

        // check right subtree
        int right = dfs(root->right, target, k);
        if (right != -1) {
            if (right + 1 == k) ans.push_back(root->val);
            else subtreeAdd(root->left, right+2, k);
            return right + 1;
        }

        return -1; // target not found
    }
};
