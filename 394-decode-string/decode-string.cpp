class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans = "";
        stack<char> stk;

        for(int i = 0; i < n; i++){
            if(s[i] != ']'){
                stk.push(s[i]);
                continue;
            }

            string ss = "";

            while(!stk.empty() && stk.top() != '['){
                ss = stk.top() + ss;
                stk.pop();
            }

            int times = 1;

            if(stk.top() == '['){
                stk.pop();
                string num = "";

                while(!stk.empty() && stk.top() >= '0' && stk.top() <= '9'){
                    num = stk.top() + num;
                    stk.pop();
                }

                if(num.size()) times = stoi(num);

                for(int j = 0; j < times; j++){
                    for(char ch : ss){
                        stk.push(ch);
                    }
                }
                
            }
            
        }

        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;

    }
};
/*

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // build number
            } else if (c == '[') {
                countStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            } else if (c == ']') {
                int times = countStack.top(); countStack.pop();
                string prev = strStack.top(); strStack.pop();
                while (times--) prev += curr;
                curr = prev;
            } else {
                curr += c; // append normal char
            }
        }

        return curr;
    }
};



*/