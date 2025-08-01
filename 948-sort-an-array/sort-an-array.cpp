class Solution {
public:
    void merge(vector<int>& nums, int i, int j){
        int mid = i + (j - i) / 2;
        int pt1 = i;
        int pt2 = mid + 1;

        vector<int> ans;

        while(pt1 <= mid && pt2 <= j){
            if(nums[pt1] <= nums[pt2]){
                ans.push_back(nums[pt1]);
                pt1++;
            }
            else{
                ans.push_back(nums[pt2]);
                pt2++;
            }
        }

        while(pt1 <= mid){
            ans.push_back(nums[pt1]);
            pt1++;
        }
        while(pt2 <= j){
            ans.push_back(nums[pt2]);
            pt2++;
        }

        for(int k = j; k >= i; k--){
            nums[k] = ans.back();
            ans.pop_back();
        }
    }
    void mergeSort(vector<int>& nums, int i, int j){
        if(i >= j) return;
        
        int mid = i + (j - i) / 2;

        mergeSort(nums, i, mid);
        mergeSort(nums, mid + 1, j);

        merge(nums, i, j);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);

        return nums;
    }
};
