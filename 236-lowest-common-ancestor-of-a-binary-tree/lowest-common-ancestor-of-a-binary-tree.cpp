class Solution {
public:
    /* 1. Level by level p and q tak pahucho by storing the parents
       2. Jab p and q dono mil jaaye unke acestors store ho jaaye toh break the loop
       3. p ke ancestors store kro...pcihhe jaake
       4. q ancestores ko travell kro if u find any matches iwth p's anchestors
       => that is the LCA.
    */
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> queue;

        parent[root] = nullptr;
        queue.push(root);

        while (!parent.count(p) || !parent.count(q)) {
            TreeNode* node = queue.front(); queue.pop();

            if (node->left) {
                parent[node->left] = node;
                queue.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                queue.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestors;

        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }
        while (!ancestors.count(q)) {
            q = parent[q];
        }

        return q;
    }
};