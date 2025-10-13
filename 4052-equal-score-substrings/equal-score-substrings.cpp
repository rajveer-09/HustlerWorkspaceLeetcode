class Solution {
public:
    bool scoreBalance(string s) {
        int tt = 0;

        for(char ch : s){
            tt += (ch - 'a' + 1);
        }
        int sum = 0;
        for(char ch : s){
            sum += (ch - 'a' + 1);

            if(tt-sum == sum){
                return true;
            }
        }

        return false;
    }
};