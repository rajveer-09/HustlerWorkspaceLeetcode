class Solution {
private:
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int largestArea = 0;
        int area;
        for(int i = 0; i < heights.size(); i++) {
            area = heights[i] * (nse[i] - pse[i] - 1);
            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
};
