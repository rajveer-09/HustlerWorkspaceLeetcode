class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        List<Integer> diff1 = new ArrayList<>();
        List<Integer> diff2 = new ArrayList<>();
        int i = 0, j = 0;
        while (i < nums1.length || j < nums2.length) {
            if (i < nums1.length && (j == nums2.length || nums1[i] < nums2[j])) {
                if (i == 0 || nums1[i] != nums1[i - 1]) {
                    diff1.add(nums1[i]);
                }
                i++;
            } else if (j < nums2.length && (i == nums1.length || nums2[j] < nums1[i])) {
                if (j == 0 || nums2[j] != nums2[j - 1]) {
                    diff2.add(nums2[j]);
                }
                j++;
            } else {
                i++;
                j++;
            }
        }
        List<List<Integer>> result = new ArrayList<>();
        result.add(diff1);
        result.add(diff2);
        
        return result;
    }
}

