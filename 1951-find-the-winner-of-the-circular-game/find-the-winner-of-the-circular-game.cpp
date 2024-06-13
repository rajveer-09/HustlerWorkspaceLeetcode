class Solution {
public:
    int findTheWinner(int n, int k) {
        return josephus(n, k) + 1; // Add 1 to convert zero-based index to one-based index
    }

private:
    int josephus(int n, int k) {
        if (n == 1) {
            return 0; // Base case: the last person standing is at index 0
        } else {
            return (josephus(n - 1, k) + k) % n;
        }
    }
};
