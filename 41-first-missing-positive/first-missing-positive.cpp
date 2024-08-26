class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool> mp;

        for(auto it : nums){
            if(it>0){
                mp[it]=true;
            }
        }

        for(int i = 1; i<=nums.size(); i++){
            if(!mp.count(i)){
                return i;
            }
        }

        return nums.size()+1;
    }
};