class Solution {
public:
    string reverseWords(string s) {

        int start = 0, end = s.size() - 1;
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;
        
       
        string reversed = "";
        for (int i = end; i >= start; i--) {
            reversed += s[i];
        }
    
        int n = reversed.size();
        int left = 0, right = 0;
        while (right < n) {
            while (right < n && reversed[right] != ' ') right++;
            reverseWord(reversed, left, right - 1);
            right++;
            left = right;
        }
        
        string result = "";
        for (int i = 0; i < n; i++) {
            if (reversed[i] != ' ' || (result.back() != ' ')) {
                result += reversed[i];
            }
        }

        return result;
    }
    
private:
    void reverseWord(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }
};
