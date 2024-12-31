class Solution {
    public boolean isPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            // Move l pointer until an alphanumeric character is found
            while (l < r && !isAlphaNumeric(s.charAt(l))) {
                l++;
            }
            // Move r pointer until an alphanumeric character is found
            while (l < r && !isAlphaNumeric(s.charAt(r))) {
                r--;
            }

            char lc = Character.toLowerCase(s.charAt(l));
            char rc = Character.toLowerCase(s.charAt(r));

            if (lc != rc) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    private boolean isAlphaNumeric(char c) {
        return (c >= 'A' && c <= 'Z') || 
               (c >= 'a' && c <= 'z') || 
               (c >= '0' && c <= '9');
    }
}