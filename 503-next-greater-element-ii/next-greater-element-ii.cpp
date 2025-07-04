class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 2; i >= 0; i--) {
            int idx = i % n;
            while (!st.empty() && st.top() <= arr[idx]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[idx] = st.top();
            }
            
            st.push(arr[idx]);
        }

        return ans;
    }
};
