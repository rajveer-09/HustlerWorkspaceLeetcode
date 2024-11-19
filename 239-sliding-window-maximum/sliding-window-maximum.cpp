class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int st = 0;
        multiset<int> ms;
        vector<int> ans;

        for (int ed = 0; ed < nums.size(); ed++) {
            ms.insert(nums[ed]);

            if (ed - st + 1 == k) {
                ans.push_back(*ms.rbegin());

                ms.erase(ms.find(nums[st]));
                st++;
            }
        }

        return ans;
    }
};
