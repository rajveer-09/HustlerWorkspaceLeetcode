public class Solution {
    public String maximumOddBinaryNumber(String s) {
        char[] chars = s.toCharArray();
        int n = chars.length;
        int i = n - 2;
        int k = 0;
        while (i >= k) {
            if (chars[i] == '1' && chars[n - 1] != '1') {
                char temp = chars[i];
                chars[i] = chars[n - 1];
                chars[n - 1] = temp;
            } else if (chars[i] == '1') {
                while (chars[k] == '1' && k < i) {
                    k++;
                }
                char temp = chars[i];
                chars[i] = chars[k];
                chars[k] = temp;
                k++;
            }
            i--;
        }
        return new String(chars);
    }
}
