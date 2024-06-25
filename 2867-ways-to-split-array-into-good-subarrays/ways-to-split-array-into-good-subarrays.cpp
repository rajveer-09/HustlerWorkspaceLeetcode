class Solution {
public:
    #define ll long long
    const int MOD = 1e9 + 7;
    
    //Idea : to find number of ways the number of Zeroes present between two adjacent Ones.

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<ll> vec;
        int s = nums.size();
        
        //Step 1 - store the position of ones 
        for(int i = 0; i < s; i++){
            if(nums[i] == 1){
                vec.push_back(i);
            }
        }
        //when no ones present 
        if(vec.size() == 0){
            return 0;
        }
        
        ll ans = 1;
        //simply take the absolute difference of position and multiply to the ans
        //also take mod at each step
        for(int i = 1; i < vec.size(); i++){
            ans = ((ans%MOD) * ((vec[i] - vec[i-1])%MOD)) % MOD;
        }
        
        return ans % MOD;
    }
};