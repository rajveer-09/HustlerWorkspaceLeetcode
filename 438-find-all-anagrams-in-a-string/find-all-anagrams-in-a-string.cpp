#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> freqP, freqS;
        
        for (char c : p) {
            freqP[c]++;
        }
        
        int left = 0, right = 0;
        int required = freqP.size();
        int formed = 0;
        
        while (right < s.size()) {
            char c = s[right];
            freqS[c]++;
            
            if (freqP.count(c) && freqS[c] == freqP[c]) {
                formed++;
            }
            
            while (formed == required) {
                if (right - left + 1 == p.size()) {
                    result.push_back(left);
                }
                
                char leftChar = s[left];
                freqS[leftChar]--;
                
                if (freqP.count(leftChar) && freqS[leftChar] < freqP[leftChar]) {
                    formed--;
                }
                
                left++;
            }
            
            right++;
        }
        
        return result;
    }
};
