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