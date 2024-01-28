class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0; 
        int major = nums[0];
		for(int i:nums) {
			if(count==0){
                 major=i; 
                 count++;
            }
			else if(i==major) count++;
			else count--;
		}
		return major;
    }
};