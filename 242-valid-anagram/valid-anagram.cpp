class Solution {
public:
    bool isAnagram(string s, string t) {

       int freqTable[26]={0};

       for(int i=0;i<s.size();i++){
           freqTable[s[i]-'a']++;
       }
       // O(n)
       for(int i=0;i<t.size();i++){
           freqTable[t[i]-'a']--;
       }
       //O(m)

       for(int i=0;i<26;i++){
           if(freqTable[i]!=0) return false;
       }
       //O(1)

       return true;
    }
};