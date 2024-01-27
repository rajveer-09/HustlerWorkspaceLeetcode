class Solution {
public:
    string addStrings(string num1, string num2) {

    int n1 = num1.size();
    int n2 = num2.size();
    string ans;
    int carry = 0;

    while (n1 > 0 || n2 > 0 || carry > 0) {
        int digit1 = (n1 > 0) ? num1[--n1] - '0' : 0;
        int digit2 = (n2 > 0) ? num2[--n2] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        ans.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
    }
};