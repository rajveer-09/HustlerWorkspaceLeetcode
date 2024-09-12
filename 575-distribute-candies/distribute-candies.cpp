class Solution {
public:
    int distributeCandies(vector<int>& c) {
        ios_base::sync_with_stdio(false);
        set<int>s(c.begin(),c.end());
        return min(c.size()/2,s.size());
    }
};