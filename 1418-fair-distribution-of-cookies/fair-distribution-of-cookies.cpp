class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k, 0); // Track cookies given to each child
        return solve(0, cookies, child, k);
    }

private:
    int solve(int idx, vector<int>& cookies, vector<int>& child, int k) {
        if (idx == cookies.size()) {
            return *max_element(child.begin(), child.end()); // Max cookies given to a single child
        }

        int minUnfairness = INT_MAX;
        for (int i = 0; i < k; ++i) {
            child[i] += cookies[idx]; // Give current cookie to i-th child
            minUnfairness = min(minUnfairness, solve(idx + 1, cookies, child, k)); // Recurse for next cookie
            child[i] -= cookies[idx]; // Backtrack
        }

        return minUnfairness;
    }
};