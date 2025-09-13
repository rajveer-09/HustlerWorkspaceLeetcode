class Solution {
private:
    TreeNode* buildBST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, start, mid - 1);
        root->right = buildBST(nums, mid + 1, end);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};