class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right =  n - 1;

        while(left <= right){
            while(left + 1 < n && nums[left] == nums[left + 1]) left++;
            while(right - 1 >= 0 && nums[right] == nums[right - 1]) right--;
            
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) return true;
            
            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
};