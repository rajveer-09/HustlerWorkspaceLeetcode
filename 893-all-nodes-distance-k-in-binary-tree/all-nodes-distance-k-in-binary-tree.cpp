class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> pp;
    void preOrdere(TreeNode* root){
        if(!root) return;

        if(root->left){
            pp[root->left] = root;
        }
        if(root->right){
            pp[root->right] = root;
        }

        preOrdere(root->left);
        preOrdere(root->right);
    }
    void bfs(TreeNode* start, int k, vector<int>& ans){
        if(!start) return;

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;

        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis.count(node->left)){
                    q.push(node->left);
                    vis[node->left] =true;
                } 
                if(node->right && !vis.count(node->right)) {
                    q.push(node->right);
                    vis[node->right] =true;
                }
                if(pp.count(node) && !vis.count(pp[node])) {
                    q.push(pp[node]);
                    vis[pp[node]] =true;
                }
            }

            k--;

            if(k == 0) break;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};

        vector<int> ans;
        pp.clear();

        preOrdere(root);
        
        bfs(target, k, ans);

        return ans;
    }
};