class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // Iterate through all indices except the last one
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest reach from the current position
            farthest = max(farthest, i + nums[i]);

            // If we've reached the end of the current jump's range
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }
        
        return jumps;
    }
};