class Solution {
public:
    

bool canWin(int maxChoosableInteger, int desiredTotal, int usedNumbers, unordered_map<int, bool>& memo) {
    if (desiredTotal <= 0) return false;
    if (memo.find(usedNumbers) != memo.end()) return memo[usedNumbers];

    for (int i = 0; i < maxChoosableInteger; ++i) {
        int currentMask = (1 << i);
        if ((usedNumbers & currentMask) == 0) { // If i-th number is not used
            if (!canWin(maxChoosableInteger, desiredTotal - (i + 1), usedNumbers | currentMask, memo)) {
                memo[usedNumbers] = true;
                return true;
            }
        }
    }

    memo[usedNumbers] = false;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal <= 0) return true;
    int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
    if (sum < desiredTotal) return false;

    unordered_map<int, bool> memo;
    return canWin(maxChoosableInteger, desiredTotal, 0, memo);
}

int main() {
    int maxChoosableInteger = 10;
    int desiredTotal = 11;
    cout << (canIWin(maxChoosableInteger, desiredTotal) ? "true" : "false") << endl;

    maxChoosableInteger = 10;
    desiredTotal = 0;
    cout << (canIWin(maxChoosableInteger, desiredTotal) ? "true" : "false") << endl;

    maxChoosableInteger = 10;
    desiredTotal = 1;
    cout << (canIWin(maxChoosableInteger, desiredTotal) ? "true" : "false") << endl;

    return 0;
}

};