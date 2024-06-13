class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // Start with the base case for 1 person
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        return winner + 1; // Convert zero-based index to one-based index
    }
};
