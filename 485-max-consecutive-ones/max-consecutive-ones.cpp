class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxi = 0;

        for(int it : nums){
            if(it == 1) {
                cnt++;
                maxi = max(maxi, cnt);
            } 
            else {
                cnt = 0;
            }
        }

        return maxi;
    }
};