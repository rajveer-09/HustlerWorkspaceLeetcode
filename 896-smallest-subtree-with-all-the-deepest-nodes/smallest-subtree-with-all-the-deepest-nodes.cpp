class Solution {
public:
    TreeNode* solve(TreeNode* root, unordered_set<int>& set){
        if(!root) return NULL;

        if(set.count(root->val)) return root;

        TreeNode* lh = solve(root->left, set);
        TreeNode* rh = solve(root->right, set);

        if(lh && rh) return root;

        if(!lh) return rh;

        return lh;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        unordered_set<int> st;

        while(!q.empty()){
            int n = q.size();
            st.clear();

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                st.insert(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        TreeNode* ans = solve(root, st);

        return ans;
    }
};