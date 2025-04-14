class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        Queue<Pair<TreeNode, Long>> queue = new LinkedList<>();

        queue.offer(new Pair<>(root, 0L));

        long maxWidth = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            long minIndex = queue.peek().getValue();
            long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                Pair<TreeNode, Long> current = queue.poll();
                TreeNode node = current.getKey();
                long index = current.getValue() - minIndex;

                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (node.left != null)
                    queue.offer(new Pair<>(node.left, 2 * index + 1));
                if (node.right != null)
                    queue.offer(new Pair<>(node.right, 2 * index + 2));
            }

            maxWidth = Math.max(maxWidth, last - first + 1);
        }

        return (int) maxWidth;
    }
}