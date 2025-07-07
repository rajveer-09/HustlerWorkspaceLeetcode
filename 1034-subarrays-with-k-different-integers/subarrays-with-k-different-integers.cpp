class Solution {
public:
    int kDistinctChar(vector<int> s, int k) {
        int ans = 0;
        unordered_map<int, int> mpp;
        int st = 0;

        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;

            while(mpp.size() > k){
                mpp[s[st]]--;
                if(mpp[s[st]] == 0){
                    mpp.erase(s[st]);
                }
                st++;
            }

            ans += (i - st + 1);
            // counting the number of valid subarrays that end at index i
            // Hence using while loop to shrink is mandatory to get valid ans for here
            // we cam optimise while with 'if' in case of finding longest problems
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // concept-> countExactlyK = countAtMostK(K) - countAtMostK(K - 1)
        
        return kDistinctChar(nums, k) - kDistinctChar(nums, k - 1);
    }
};
