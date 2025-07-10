class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        map<string, int> mpp;

        for(int i = 0; i < s.size() - 9; i++){
            string ss = s.substr(i, 10);
            // cout<<ss<<" ";
            mpp[ss]++;
        }

        vector<string> ans;

        for(auto it : mpp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};