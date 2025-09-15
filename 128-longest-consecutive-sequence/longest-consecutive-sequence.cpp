class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1, curr = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) continue; // skip duplicates
            if (nums[i] == nums[i-1] + 1) {
                curr++;
                longest = max(longest, curr);
            } else {
                curr = 1;
            }
        }
        
        return longest;
    }
    // int longestConsecutive(vector<int>& nums) {
    //     unordered_set<int> st = {nums.begin(), nums.end()};
    //     int maxLen = 0;

    //     for(int it : st){
    //         if(!st.count(it - 1)){
    //             int x = it;
    //             int cnt = 1;

    //             while(st.count(x + 1)){
    //                 cnt++;
    //                 x = x + 1;
    //             }

    //             maxLen = max(maxLen, cnt);
    //         }
    //     }

    //     return maxLen;
    // }
};