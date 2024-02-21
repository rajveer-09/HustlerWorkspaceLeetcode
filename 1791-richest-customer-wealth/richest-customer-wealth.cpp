class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
    for (const auto& customer : accounts) {
        int customerWealth = accumulate(customer.begin(), customer.end(), 0);
        res = max(res, customerWealth);
    }
    return res;
    }
};