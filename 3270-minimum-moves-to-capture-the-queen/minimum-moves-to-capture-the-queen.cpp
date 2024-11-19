class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Check if the rook can capture the queen directly
        bool horizontalCheck = (a == e) && !((a == c) && (d > std::min(b, f)) && (d < std::max(b, f)));
        bool verticalCheck = (b == f) && !((b == d) && (c > std::min(a, e)) && (c < std::max(a, e)));

        // Check if the bishop can capture the queen directly
        bool diagonal1 = (c - d == e - f) && !((c - d == a - b) && (a > std::min(c, e)) && (a < std::max(c, e)));
        bool diagonal2 = (c + d == e + f) && !((c + d == a + b) && (a > std::min(c, e)) && (a < std::max(c, e)));

        // If either piece can capture the queen in one move, return 1
        if (horizontalCheck || verticalCheck || diagonal1 || diagonal2) {
            return 1;
        }

        // Otherwise, it will take at least 2 moves
        return 2;
    }
};
