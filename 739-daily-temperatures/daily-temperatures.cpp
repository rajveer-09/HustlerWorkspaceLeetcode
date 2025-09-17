class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;

        for (int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top() - i;
            }

            stk.push(i);
        }

        return ans;
    }
};