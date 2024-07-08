class Solution {
public:
    int findTheWinner(int n, int k) {
        return josephus(n, k) + 1; 
    }

private:
    int josephus(int n, int k) {
        if (n == 1) {
            return 0; 
        } else {
            return (josephus(n - 1, k) + k) % n;
        }
    }
};
