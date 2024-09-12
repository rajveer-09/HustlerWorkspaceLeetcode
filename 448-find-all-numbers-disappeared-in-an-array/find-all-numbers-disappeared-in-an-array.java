class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;

        int[] v = new int[n + 1];

        for (int i = 0; i < n; i++) {
            v[nums[i]] = 1;
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            if (v[i] == 1) continue;
            else ans.add(i);
        }

        return ans;
    }
}