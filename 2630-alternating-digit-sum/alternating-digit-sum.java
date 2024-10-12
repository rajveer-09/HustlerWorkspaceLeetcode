class Solution {
    public int alternateDigitSum(int n) {
        String str = Integer.toString(n);
        int sum = 0;
        boolean add = true;
        
        for (char c : str.toCharArray()) {
            int digit = c - '0';
            if (add) {
                sum += digit;
            } else {
                sum -= digit;
            }
            add = !add;
        }
        
        return sum;
    }
}
