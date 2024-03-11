class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> leftArr;
        vector<int> rightArr;

        int pivotCnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == pivot){
                pivotCnt++;
            }else if(nums[i] < pivot){
                leftArr.push_back(nums[i]);
            }else{
                rightArr.push_back(nums[i]);
            }
        }
        for(int i=0; i<pivotCnt; i++){
            leftArr.push_back(pivot);
        }
        for(auto it : rightArr){
            leftArr.push_back(it);
        }
        return leftArr;
    }
};