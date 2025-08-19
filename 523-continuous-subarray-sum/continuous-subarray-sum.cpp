class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            int rem = (sum % k + k) % k;
            // sum can be neg and hence sum % k can be neg

            if(mpp.count(rem)){
                if(i - mpp[rem]  >= 2) return true;
            }
            else{
                mpp[rem] = i;
            }

            
        }

        return false;
    }
};