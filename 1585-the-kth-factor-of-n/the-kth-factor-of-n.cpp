class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> factors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                factors.insert(i);
                if (i != n / i) {  
                    factors.insert(n / i);
                }
            }
        }
        
        if (k > factors.size()) return -1;

        auto it = factors.begin();
        advance(it, k - 1);
        return *it;
    }
};
