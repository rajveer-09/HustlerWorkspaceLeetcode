class Solution {
    public boolean hasPathSum(TreeNode node, int sum) {
        if (node == null) {
            return false;
        }

       
        if (node.left == null && node.right == null && sum == node.val){
            return true;
        }

        // Recur down the left and right subtrees
        int remSum = sum - node.val;
        
        return hasPathSum(node.left, remSum) || hasPathSum(node.right, remSum);
    }
}
