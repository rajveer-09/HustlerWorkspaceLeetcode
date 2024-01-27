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
        int index=0;
        int sum=0;
        while(index<s.size()-1){
            if(num(s[index])<num(s[index+1])) sum-=num(s[index]);
            else if(num(s[index])>num(s[index+1])) sum+=num(s[index]);
            else sum+=num(s[index]);
            index++;
        }
        sum+=num(s[index]);
        return sum;
    }
};