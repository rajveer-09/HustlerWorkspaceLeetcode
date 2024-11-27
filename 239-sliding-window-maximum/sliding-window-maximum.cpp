class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        int st = 0;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});

            if (i - st + 1 == k) {
                while (pq.top().second < st) {
                    pq.pop();
                }

                ans.push_back(pq.top().first);

                st++;
            }
        }

        return ans;
    }
};