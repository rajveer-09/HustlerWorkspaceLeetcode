class Solution {
    public int thirdMax(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        // Convert the set to a list and sort it
        List<Integer> list = new ArrayList<>(set);
        Collections.sort(list);

        if (list.size() < 3) {
            return list.get(list.size() - 1);
        }

        return list.get(list.size() - 3);
    }
}