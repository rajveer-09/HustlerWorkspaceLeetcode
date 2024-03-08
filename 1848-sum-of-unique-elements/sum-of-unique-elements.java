class Solution {
    public int sumOfUnique(int[] nums) {
        int[] frequency = new int[101];
        int sum = 0;

        for (int num : nums) {
            frequency[num]++;
        }

        for (int i = 0; i <= 100; i++) {
            if (frequency[i] == 1) {
                sum += i;
            }
        }

        return sum;
    }
}

