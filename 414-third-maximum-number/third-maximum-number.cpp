class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;

        for(auto it : nums) st.insert(it);

        int n = st.size();

        if(n < 3){
            auto it = st.begin();
            advance(it, n-1);
            return *it;
        }

        auto it = st.begin();
        advance(it, n-3);

        return *it ;
    }
};