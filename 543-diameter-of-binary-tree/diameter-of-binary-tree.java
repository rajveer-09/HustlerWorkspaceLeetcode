class Solution {
    public int height(TreeNode root, int arr[]){
        if(root == null) return 0;

        int lh = height(root.left, arr);
        int rh = height(root.right, arr);

        arr[0] = Math.max(arr[0], lh + rh);

        return Math.max(lh, rh) + 1;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        if(root ==  null) return 0;
        int arr[] = new int[1];

        height(root, arr);

        return arr[0];
    }
}