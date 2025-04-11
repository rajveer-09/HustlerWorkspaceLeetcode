class Solution {
    public void helper(TreeNode root, List<Integer> result){
        if(root == null) return;

        if(root.left == null && root.right == null){
            result.add(root.val);
            return;
        }
   

        helper(root.left, result);

        result.add(root.val);

        helper(root.right, result);

    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        helper(root, result);

        return result;
    }
}