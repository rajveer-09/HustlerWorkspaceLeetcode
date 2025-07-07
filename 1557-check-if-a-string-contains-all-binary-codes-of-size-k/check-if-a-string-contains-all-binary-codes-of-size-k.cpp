class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        
        unordered_set<string> seen;
        long long total = 1 << k; // 2^k

        for (int i = 0; i <= s.size() - k; i++) {
            // saare subarray k length ke daal do
            // agr unique combos of len => agr limit tak ban gye..then..okay
            string sub = s.substr(i, k);
            seen.insert(sub);

            if (seen.size() == total) return true; // early stop
        }

        return false;
    }
};
