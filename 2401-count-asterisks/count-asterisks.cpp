class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        int flag = 0;

        for (char c : s) {
            if (c == '|') {
                flag++;
            }
            if ((flag & 1) == 0 && c == '*') {
                count++;
            }
        }
        return count;
    }
};