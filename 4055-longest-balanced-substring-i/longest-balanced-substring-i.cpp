class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            unordered_map<int, int> mpp;
            int maxi = 0;
            for(int j = i; j < s.size(); j++){
                mpp[s[j]]++;

                maxi = max(maxi, mpp[s[j]]);

                bool flg = false;

                for(auto [val, freq] : mpp){
                    if(freq != maxi){
                        flg = true;
                        break;
                    }
                }

                if(!flg){
                    ans = max(ans, j - i + 1);
                }
            }

           
        }

        return ans;
    }
};