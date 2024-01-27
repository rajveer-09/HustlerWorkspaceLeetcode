class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
    
    // Thousands place
    roman += string(num / 1000, 'M');
    num %= 1000;
    
    // Hundreds place
    if (num >= 900) {
        roman += "CM";
        num -= 900;
    } else if (num >= 500) {
        roman += "D";
        num -= 500;
    } else if (num >= 400) {
        roman += "CD";
        num -= 400;
    }
    roman += string(num / 100, 'C');
    num %= 100;
    
    // Tens place
    if (num >= 90) {
        roman += "XC";
        num -= 90;
    } else if (num >= 50) {
        roman += "L";
        num -= 50;
    } else if (num >= 40) {
        roman += "XL";
        num -= 40;
    }
    roman += string(num / 10, 'X');
    num %= 10;
    
    // Ones place
    if (num >= 9) {
        roman += "IX";
        num -= 9;
    } else if (num >= 5) {
        roman += "V";
        num -= 5;
    } else if (num >= 4) {
        roman += "IV";
        num -= 4;
    }
    roman += string(num, 'I');
    
    return roman;
    }
};