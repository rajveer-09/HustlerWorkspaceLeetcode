class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nichhe sabse largest ko safe rakhna hai...
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);

            while(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};