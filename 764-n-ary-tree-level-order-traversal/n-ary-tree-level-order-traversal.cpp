class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;

        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                for (Node* child : node->children) {
                    q.push(child);
                }
            }

            ans.push_back(currentLevel);
        }
        
        return ans;
    }
};