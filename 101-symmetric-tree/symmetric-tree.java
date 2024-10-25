class Solution {
    public boolean isSymmetric(TreeNode root) {

        return root == null || isMirror(root.left, root.right);
    }

    private boolean isMirror(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        }
        
        // If only one is null, they are not symmetric
        if (left == null || right == null) {
            return false;
        }

        // Check if values are equal and subtrees are mirrors
        return (left.val == right.val) &&
               isMirror(left.left, right.right) &&
               isMirror(left.right, right.left);
    }
}

