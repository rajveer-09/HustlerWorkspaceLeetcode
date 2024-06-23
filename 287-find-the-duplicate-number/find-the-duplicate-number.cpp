class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int freq[100001] = {0};
        for(int i = 0; i <n; i++){
            if(freq[nums[i]] == 0){
                freq[nums[i]] += 1;
            }
            else{
                return nums[i];
            }
        }
        return 0;
    }
};