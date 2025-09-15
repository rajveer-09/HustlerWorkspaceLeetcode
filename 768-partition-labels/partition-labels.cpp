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
        int st = -1;

        while(curr < n){
            farthest = max(farthest, mpp[s[curr]]);

            if(curr == farthest){
                ans.push_back(curr - st);
                st = curr;
            }

            curr++;
        }

        return ans;
    }
};