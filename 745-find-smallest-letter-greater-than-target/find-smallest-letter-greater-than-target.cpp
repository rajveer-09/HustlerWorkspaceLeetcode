class Solution {
public:
    char nextGreatestLetter(vector<char>& A, char target) {
        // Use upper_bound instead to find the smallest element strictly greater than the target
        auto it = upper_bound(A.begin(), A.end(), target);
        
        // If no element is greater than the target, return the first element (circular nature)
        if (it == A.end()) {
            return A[0];
        }

        return *it;
    }
};
