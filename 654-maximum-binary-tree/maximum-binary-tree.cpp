class Solution {
private:
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int maxIdx = l;

        for (int i = l + 1; i <= r; ++i) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxIdx]);
        
        root->left = construct(nums, l, maxIdx - 1);
        root->right = construct(nums, maxIdx + 1, r);
        
        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};