class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // ensures lexicographical order
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return ans;
    }

};
/*

-> The next_permutation(nums.begin(), nums.end()) function in C++ performs two actions:
-> It modifies the nums container in-place to the next lexicographically greater permutation.
-> It returns a boolean value:
1. true if a next lexicographically greater permutation was found and the container was rearranged.
2. false if the current permutation is the largest possible (e.g., [3, 2, 1]), in which case -> it rearranges the container to the lowest possible order (ascending order, e.g., [1, 2, 3]).

*/