class Solution {
public:
    vector<vector<unordered_map<int,int>>> dp;
    int f(vector<int>&nums, vector<int>&andVals, int i, int arrayNo, int ans){
        if(i>=nums.size()){
            if(arrayNo==andVals.size()) return 0;
            else return 1e9;
        }
        
        if(arrayNo==andVals.size()){
            return 1e9;
        }
        
        if(dp[i][arrayNo].count(ans)) return dp[i][arrayNo][ans];
        
        int r1 = 1e9;
        if((ans&nums[i]) == andVals[arrayNo]){
            r1 = nums[i]+f(nums,andVals,i+1,arrayNo+1,(1<<19)-1);
        }
        int r2 = f(nums,andVals,i+1,arrayNo,ans&nums[i]);
        return dp[i][arrayNo][ans] = min(r1,r2);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {        
        dp.resize(nums.size()+2,vector<unordered_map<int,int>>(11));
        int n = f(nums,andValues,0,0,(1<<19)-1);
        return n==1e9?-1:n;
    }
};