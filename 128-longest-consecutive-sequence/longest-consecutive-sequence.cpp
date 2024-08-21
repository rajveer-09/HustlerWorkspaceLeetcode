class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(int it : nums) st.insert(it);

        int ans = 0;
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(st.count(nums[i]-1)){
                continue;
            }
            int x = nums[i];
            int cnt=1;
            while(st.count(x+1)){
                cnt++;
                x++;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};