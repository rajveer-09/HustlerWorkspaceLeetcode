class Solution {
    public void inorder(TreeNode root, ArrayList<Integer> ans) {
        if (root == null) return;

        inorder(root.left, ans);

        ans.add(root.val);
        
        inorder(root.right, ans);
    }

    public boolean isValidBST(TreeNode root) {
        ArrayList<Integer> ans = new ArrayList<>();
        inorder(root, ans);

        for (int i = 1; i < ans.size(); i++) {
            if (ans.get(i) <= ans.get(i - 1)) return false;
        }

        return true;
    }
}