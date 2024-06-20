class Solution {
public:
    int jump(vector<int>& nums) {
        int jmps=0;
        int lft=0, rht=0;

        for(int i=0;i<nums.size()-1; i++){
            rht = max(rht, i+nums[i]);
            if(i==lft){
                jmps++;
                lft= rht;
            }
        }

        return jmps;
    }
};