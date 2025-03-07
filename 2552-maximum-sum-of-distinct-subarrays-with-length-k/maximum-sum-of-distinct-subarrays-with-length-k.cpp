class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int st = 0;
        long long ans = 0;
        long long sum = 0;

        map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
            sum += nums[i];

            if(mpp[nums[i]] >= 2){
                while(mpp[nums[i]] >= 2){
                    mpp[nums[st]]--;
                    sum -= nums[st];

                    if(mpp[nums[st]] == 0){
                        mpp.erase(nums[st]);
                    }
                    
                    st++;
                }
            }

            if(i - st + 1 == k){
                if(mpp.size() == k){
                    ans = max(ans, sum);
                    
                }

                mpp[nums[st]]--;
                sum -= nums[st];

                if(mpp[nums[st]] == 0){
                    mpp.erase(nums[st]);
                }
                
                st++;


            }
        }

        return ans;
    }
};