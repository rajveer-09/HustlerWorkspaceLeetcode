#include <unordered_map>

class Solution {
public:
    int fib(int n) {
        std::unordered_map<int, int> memo;
        return fibMemo(n, memo);
    }

private:
    int fibMemo(int n, std::unordered_map<int, int>& memo) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
        return memo[n];
    }
};
