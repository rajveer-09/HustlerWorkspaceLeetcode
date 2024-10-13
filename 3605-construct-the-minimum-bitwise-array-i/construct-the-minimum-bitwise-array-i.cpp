class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans.push_back(-1);
                continue; 
            }
            int x = nums[i] + 1;

            if (!(x & (x - 1))) {
                ans.push_back(nums[i] / 2);
            } 
            else {
                int minAns = nums[i];
                for (int j = 0; j <= 31; j++) { 
                    int p = (nums[i] & (1 << j));
                    int q = nums[i] ^ (1 << j);

                    if (p == 0) break;

                    minAns = min(minAns, q);
                }
                ans.push_back(minAns);
            }
        }

        return ans;
    }
};
