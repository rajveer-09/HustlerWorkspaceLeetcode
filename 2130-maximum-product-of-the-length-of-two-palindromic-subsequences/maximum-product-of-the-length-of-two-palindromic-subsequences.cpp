class Solution {
public:
    int ans = 0;

    bool isPalindrome(string str) {
        int i = 0, j = str.size() - 1;
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void dfs(int index, string s, string& s1, string& s2) {
        if (index >= s.size()) {
            if (isPalindrome(s1) && isPalindrome(s2)) {
                int temp = s1.size() * s2.size();
                ans = max(ans, temp);
            }
            return;
        }

        dfs(index + 1, s, s1, s2);

        s1.push_back(s[index]);
        dfs(index + 1, s, s1, s2);

        s1.pop_back();

        s2.push_back(s[index]);
        dfs(index + 1, s, s1, s2);
        s2.pop_back();
    }

    int maxProduct(string s) {
        string s1 = "", s2 = "";

        dfs(0, s, s1, s2);

        return ans;
    }
};