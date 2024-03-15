class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool flag = true;
        for (int i = 0; i < nums.size();++i){
            if (nums[i] == 0)
                return 0;
            if (nums[i] < 0)
                flag = !flag;
        }
        if (flag)
            return 1;
        return -1;
    }
};