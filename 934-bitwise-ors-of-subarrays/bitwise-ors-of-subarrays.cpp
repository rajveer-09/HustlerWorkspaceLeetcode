class Solution {
public:
    int subarrayBitwiseORs(vector<int>& inputVector) {
        vector<int> res;
    unordered_set<int>ans;
    int left = 0, right;
    for (int a : inputVector) {
        right = res.size();
        res.push_back(a);
        for (int i = left; i < right; ++i) {
            if (res.back() != (res[i] | a)) {
                res.push_back(res[i] | a);
            }

        }

        left = right;
    }

    // Storing the OR values calculated in vector in a set to get the count of distinct values.
    for (int i = 0; i < res.size(); i++)
    {
        ans.insert(res[i]);
    }

    return ans.size();
    }
};