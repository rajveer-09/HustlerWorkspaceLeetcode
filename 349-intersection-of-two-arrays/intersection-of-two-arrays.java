class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        boolean[] arr1 = new boolean[1001];
        boolean[] arr2 = new boolean[1001];
        
        for (int num : nums1) {
            arr1[num] = true;
        }
        for (int num : nums2) {
            arr2[num] = true;
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i <= 1000; i++) {
            if (arr1[i] && arr2[i]) {
                list.add(i);
            }
        }
        int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ans[i] = list.get(i);
        }
    
        return ans;
    }
}
