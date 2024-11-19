class Solution {
public:
    bool isVowel(char& ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;

        return false;
    }

    int count(const unordered_map<char, int>& mp){
        int cnt = 0;
        for(auto& it : mp){
            cnt += it.second;
        }

        return cnt;
    }

    int maxVowels(string s, int k) {
        unordered_map<char, int> mp;

        int st = 0;
        int maxi = 0;

        for(int ed = 0; ed < s.size(); ed++){
            if(isVowel(s[ed])){
                mp[s[ed]]++;
            }

            if(ed - st + 1 == k){
                maxi = max(maxi, count(mp));
                if(isVowel(s[st])){
                    mp[s[st]]--;
                }
                st++;
            }
        }

        return maxi;
    }
};