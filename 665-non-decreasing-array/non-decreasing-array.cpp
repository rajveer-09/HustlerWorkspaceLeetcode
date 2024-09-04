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
        int cnt = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                cnt++;
                if (cnt > 1)
                    return false;

                if (i > 1 && nums[i] < nums[i - 2]) {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return true;
    }
};