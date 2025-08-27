class Solution {
public:
    vector<int> original;
    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
        original = nums;
    }
    
    vector<int> reset() {
        nums = original;
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = nums;
        for (int i = shuffled.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1); // pick random index in [0, i]
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};
