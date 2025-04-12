class Solution {
    public int count(TreeNode root){
        if(root == null) return 0;
        if(root.left == null && root.right == null) return 1;

        int l = count(root.left);
        int r = count(root.right);

        return l + r + 1;

    }
    public int countNodes(TreeNode root) {
        if(root == null) return 0;

        return count(root);
    }
}