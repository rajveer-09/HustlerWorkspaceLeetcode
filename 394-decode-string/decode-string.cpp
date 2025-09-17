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