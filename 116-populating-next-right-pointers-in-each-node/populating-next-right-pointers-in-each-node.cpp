class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();

                if(i < n - 1) node->next = q.front();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

        }

        return root;
    }
};