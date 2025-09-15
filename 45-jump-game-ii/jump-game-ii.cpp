class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0;

        for(int i = 0; i < n - 1; i++){
            int maxi = i + 1;
            if(i + nums[i] >= n - 1) return jump + 1;
            for(int j = i + 1; j <= i + nums[i] && j < n; j++){
                if(nums[maxi] + maxi <= nums[j] + j){
                    maxi = j;
                }
            }

            i = maxi - 1;
            jump++;
        }

        return jump;
    }
};