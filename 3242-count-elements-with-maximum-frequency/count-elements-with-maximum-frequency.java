class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] freq = new int[101];
        
        for (int num : nums) {
            freq[num]++;
        }

        int maxFreq = freq[0];
        int count = 0;
        
        for (int i = 1; i <= 100; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }
        for (int i = 1; i <= 100; i++) {
            if (freq[i] == maxFreq) {
                count += maxFreq;
            }
        }
        return count;
    }
}
