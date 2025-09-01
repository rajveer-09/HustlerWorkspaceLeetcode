class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for(char ch : s){
            if(ch == '('){
                low++;
                high++;
            }
            else if(ch == ')'){
                low--;
                high--;
            }
            else{ // '*'
                low--;   // use '*' as ')'
                high++;  // use '*' as '('
            }

            if(high < 0) return false;   // too many ')'
            low = max(low, 0);           // can't go below 0
        }

        return low == 0;
    }
};
/*
=>low: minimum possible open count (treat * as ))
=>high: maximum possible open count (treat * as ()
*/
