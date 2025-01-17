class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0;
        int ans = 0;
        unordered_map<int, pair<int, int>> mpp;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & 1){
                cnt++;
            }

            if(cnt == k) ans++;

            if(mpp.count(cnt - k)){
                ans += mpp[cnt - k].second - mpp[cnt - k].first + 1;
            }

            if(mpp.count(cnt)){
                mpp[cnt].second = i;
            }
            else{
                mpp[cnt] = {i, i};
            }
        }

        return ans;
    }
};