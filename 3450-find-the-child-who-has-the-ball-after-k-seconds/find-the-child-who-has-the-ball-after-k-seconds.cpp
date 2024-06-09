class Solution {
public:
    int numberOfChild(int n, int k) {
        int cycleLength = 2 * (n - 1);
    // Calculate the effective steps
    int effectiveK = k % cycleLength;

    // Initialize position and direction
    int position = 0;
    int direction = 1; // 1 means right, -1 means left

    // Simulate the passing of the ball for effectiveK steps
    for (int i = 0; i < effectiveK; ++i) {
        position += direction;
        if (position == 0 || position == n - 1) {
            direction = -direction;
        }
    }

    return position;
    }
};