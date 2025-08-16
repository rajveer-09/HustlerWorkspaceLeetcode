class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        getSum(root, freq, maxFreq);

        vector<int> result;
        for (auto const& [sum, count] : freq) {
            if (count == maxFreq) {
                result.push_back(sum);
            }
        }

        return result;
    }

private:
    int getSum(TreeNode* node, unordered_map<int, int>& freq, int& maxFreq) {
        if (!node) {
            return 0;
        }

        int leftSum = getSum(node->left, freq, maxFreq);
        int rightSum = getSum(node->right, freq, maxFreq);

        int currentSum = node->val + leftSum + rightSum;

        freq[currentSum]++;
        
        maxFreq = max(maxFreq, freq[currentSum]);

        return currentSum;
    }
};