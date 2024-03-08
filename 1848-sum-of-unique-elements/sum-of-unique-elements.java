class Solution {
    public int sumOfUnique(int[] nums) {
        int[] frequency = new int[201];
        int sum = 0;

        for (int num : nums) {
            frequency[num + 100]++;
        }

        for (int i = 0; i < 201; i++) {
            if (frequency[i] == 1) {
                sum += i - 100;
            }
        }

        return sum;
    }
}

