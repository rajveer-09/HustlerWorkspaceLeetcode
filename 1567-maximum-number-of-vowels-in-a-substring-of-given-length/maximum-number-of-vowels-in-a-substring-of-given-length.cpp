class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int left = 0;
        int maxV = 0;
        int currV = 0;

        for (int right = 0; right < s.size(); right++) {
            if (isVowel(s[right])) {
                currV++;
            }

            if (right - left + 1 > k) {
                if (isVowel(s[left])) {
                    currV--;
                }
                left++;
            }

            if (right - left + 1 == k) {
                maxV = max(maxV, currV);
            }
        }

        return maxV;
    }
};