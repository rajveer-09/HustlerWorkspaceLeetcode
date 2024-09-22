class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string, int> mp;

        for(auto s : bannedWords){
            mp[s]++;
        }

        int cnt = 0;

        for(auto s : message){
            // if(mp[s] >= 2) return true;

            if(mp[s] > 0) cnt++;

            if(cnt >= 2) return true;
        }

        return false;
    }
};