class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, maxi = 0;

        for (char c : s) {
            if (c == '(') {
                cnt++;
                maxi = max(maxi, cnt);
            } 
            else if (c == ')') {
                cnt--;
            }
        }

        return maxi;
    }
};