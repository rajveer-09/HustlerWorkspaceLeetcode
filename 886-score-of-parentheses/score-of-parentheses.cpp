class Solution {
public:
    int scoreOfParentheses(string S) {
        int count = 0;
        stack<int> st;

        for (char c : S) {
            if (c == '(') {
                st.push(0);
            } else {
                int val = 0;
                
                while (st.top() != 0) {
                    val += st.top();
                    st.pop();
                }

                st.pop();
                st.push(max(2 * val, 1));
            }
        }
        while (!st.empty()) {
            count += st.top();
            st.pop();
        }

        return count;
    }
};