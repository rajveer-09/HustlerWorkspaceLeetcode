class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (((i - cnt) % 2 == 0 && nums[i] == nums[i + 1]))
                cnt++;
        }

        if ((nums.size() - cnt) % 2) cnt++;

        return cnt;
    }
};
