class Solution {
public:
    // External helper function to compute LIS
    int LIS(vector<int>& nums) {
        vector<int> lis;
        for (int x : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) lis.push_back(x);
            else *it = x;
        }
        return lis.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort by width increasing, and height decreasing when width equal
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        // Step 2: Extract heights
        vector<int> heights;
        for (auto& env : envelopes) {
            heights.push_back(env[1]);
        }

        // Step 3: Call the LIS function on heights
        return LIS(heights);
    }
};
