class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;

        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> st; // indexes

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                res[i] = nums[st.top()];
            }

            st.push(i);
        }

        return res;
    }
};
