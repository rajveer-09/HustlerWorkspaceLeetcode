class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) {
            return 0;
        }

        long long maxSum = LLONG_MIN;
        int maxLevel = 1;
        int currentLevel = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            long long currentSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentSum += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxLevel = currentLevel;
            }
            currentLevel++;
        }
        
        return maxLevel;
    }
};