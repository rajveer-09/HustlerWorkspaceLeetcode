class Solution {
public:
    int partitionString(string s) {
        
        int ans = 0;
        int n = s.size();

        for(int i = 0; i < n; ){
            unordered_set<char> st;

            while(i < n && !st.count(s[i])){
                st.insert(s[i]);
                i++;
            }

            ans++;
        }

        return ans;
    }
};