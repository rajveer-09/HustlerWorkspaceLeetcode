class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        map<int, int> mp;

        for(int i = 0; i<nums.size(); i++){
            int rem = target-nums[i];
            if(mp.count(rem)){
                return {mp[rem], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};