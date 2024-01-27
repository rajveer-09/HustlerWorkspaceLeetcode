class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Iterate through the arrays to construct the Roman numeral string
    string roman;
    for (int i = 0; i < symbols.size(); i++) {
        while (num >= values[i]) {
            roman += symbols[i];
            num -= values[i];
        }
    }
    return roman;
    }
};