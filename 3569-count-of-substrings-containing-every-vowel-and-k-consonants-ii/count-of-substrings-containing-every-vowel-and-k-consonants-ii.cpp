class Solution {
public:
    long long atLeast(string& s, int k, int n) {
        unordered_map<char, int> vow = {{'a',1}, {'e',1}, {'i',1}, {'o',1}, {'u',1}};
        int st = 0, cntVow = 0, cntCons = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (vow.find(s[i]) == vow.end()) {
                cntCons++;
            } else {
                vow[s[i]]--;
                if (vow[s[i]] == 0) cntVow++;
            }

            while (st <= i && cntVow == 5 && cntCons >= k) {
                ans += (n - i);

                if (vow.find(s[st]) == vow.end()) {
                    cntCons--;
                } else {
                    vow[s[st]]++;
                    if (vow[s[st]] == 1) cntVow--;
                }

                st++;
            }
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        return atLeast(word, k, n) - atLeast(word, k + 1, n);
    }
};
/*
-> atLeast(k) → all substrings with k ya usse zyada consonants
-> atLeast(k + 1) → all substrings with k+1 ya usse zyada consonants

Toh in dono ka difference hi hoga exactly k consonants wale

*/