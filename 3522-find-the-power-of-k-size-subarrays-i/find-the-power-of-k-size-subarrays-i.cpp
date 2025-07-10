class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return nums; 
        vector<int> ans;
        int st = 0;

        int len = 1;

        for(int i = 1; i < n; i++){

            if(nums[i] == nums[i - 1] + 1){
                len++;
            }
            else{
                len = 1;
            }

            if(i - st + 1 == k){
                if(len >= k) {
                    ans.push_back(nums[i]);
                }
                else{
                    ans.push_back(-1);
                }
                st++;

                if(len == k) len--;
            }

            
        }

        return ans;
    }
};