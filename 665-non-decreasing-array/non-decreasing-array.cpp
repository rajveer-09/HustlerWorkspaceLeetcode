#pragma GCC target("tune=native")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("Os")
// Code here is optimized for size

static const auto fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] <= nums[i + 1]) continue;

            if (changed) return false;

            if (i == 0 || nums[i + 1] >= nums[i - 1]) {
                nums[i] = nums[i + 1];
            } else {
                nums[i + 1] = nums[i];
            }
            changed = true;
        }

        return true;
    }
};
