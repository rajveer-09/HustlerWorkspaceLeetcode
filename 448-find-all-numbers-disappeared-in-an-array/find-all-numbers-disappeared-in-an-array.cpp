class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n = nums.size();

        vector<int> v(n+1, 0);

        for(int i = 0; i < n; i++){
            v[nums[i]] = 1;
        }

        vector<int> ans;

        for(int i = 1; i <= n; i++){
            if(v[i] == 1) continue;
            else ans.push_back(i);
        }

        return ans;
    }
};