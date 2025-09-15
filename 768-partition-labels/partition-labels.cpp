class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        
        for(int i = 0; i < n; i++){
            mpp[s[i]] = i;
        }

        vector<int> ans;

        int farthest = 0;
        int curr = 0;
        int st = 0;

        while(curr < n){
            farthest = max(farthest, mpp[s[curr]]);

            if(curr == farthest){
                ans.push_back(curr - st + 1);
                st = curr + 1;
            }

            curr++;
        }

        return ans;
    }
};