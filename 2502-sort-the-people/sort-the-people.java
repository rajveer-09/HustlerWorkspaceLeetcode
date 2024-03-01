class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        for (int i = 0; i < n - 1; i++) {
            int maxIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (heights[j] > heights[maxIndex]) {
                    maxIndex = j;
                }
            }
            String tempName = names[i];
            names[i] = names[maxIndex];
            names[maxIndex] = tempName;

            int tempHeight = heights[i];
            heights[i] = heights[maxIndex];
            heights[maxIndex] = tempHeight;
        }
        return names;
    }
}