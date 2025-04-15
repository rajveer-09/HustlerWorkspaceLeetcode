class Solution {
    public TreeNode InOrder(TreeNode root, int val){
        if(root == null) return null;
        if(root.val == val) return root;


        TreeNode left = InOrder(root.left, val);
        TreeNode right = InOrder(root.right, val);

        if(left != null) return left; 

        return right;
 
    }
    public TreeNode searchBST(TreeNode root, int val) {
        return InOrder(root, val);
    }
}