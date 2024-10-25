class Solution {
    public int minDepth(TreeNode root) {
        return height(root);
    }

    public int height(TreeNode root){
        if(root==null){
            return 0;
        }

        int left = height(root.left);
        int right = height(root.right);

        if(left==0 && right!=0){
            return right+1;
        }
        else if(left!=0 && right==0){
            return left+1;
        }
        return Math.min(left, right)+1;
    }
}