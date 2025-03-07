class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st = 0, ans = 0;
        map<char, int> mpp;

        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;

            while(mpp[s[i]] > 1){
                mpp[s[st]]--;
                if(mpp[s[st]] == 0){
                    mpp.erase(s[st]);
                }
                st++;
            }

            ans = max(ans, i - st + 1);
        }

        return ans;
    }
};