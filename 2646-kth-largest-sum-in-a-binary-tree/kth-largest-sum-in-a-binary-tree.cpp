class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) {
            return -1;
        }

        queue<TreeNode*> q;
        q.push(root);
        
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

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
            
            minHeap.push(currentSum);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        if (minHeap.size() < k) {
            return -1;
        }
        
        return minHeap.top();
    }
};