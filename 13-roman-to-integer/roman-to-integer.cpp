class Solution {
public:
    int num(char ch){
        if(ch=='I') return 1;
        else if(ch=='V') return 5;
        else if(ch=='X') return 10;
        else if(ch=='L') return 50;
        else if(ch=='C') return 100;
        else if(ch=='D') return 500;
        else if(ch=='M') return 1000;

        return -1;
    }
    int romanToInt(string s) {
        int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        int current = num(s[i]);
        int next = (i + 1 < s.size()) ? num(s[i + 1]) : 0;
        if (current < next) {
            sum -= current;
        } else {
            sum += current;
        }
    }
    return sum;
    }
};