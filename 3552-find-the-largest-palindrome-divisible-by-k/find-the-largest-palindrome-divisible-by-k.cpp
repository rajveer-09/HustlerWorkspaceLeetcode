class Solution {
public:
    bool isDivisibleBy7(string& s) {
        int remainder = 0;
        for (char c : s) {
            remainder = (remainder * 10 + (c - '0')) % 7;
        }
        return remainder == 0;
    }
    string largestPalindrome(int n, int k) {
        string ans="";
        if(k==1||k==3||k==9){
            for(int i=1;i<=n;i++){
                ans+='9';
            }
        }else if(k==2){
            if(n==1){
                ans+='8';
            }else if(n==2){
                ans+="88";
            }else{
                ans+='8';
                for(int i=0;i<n-2;i++){
                    ans+='9';
                }
                ans+='8';
            }
        }else if(k==4){
            if(n==1){
                ans+='8';
            }else if(n==2){
                ans+="88";
            }else if(n==3){
                ans+="888";
            }else{
                ans+="88";
                for(int i=0;i<n-4;i++){
                    ans+='9';
                }
                ans+="88";
            }
        }else if(k==5){
            if(n==1){
                ans+='5';
            }else if(n==2){
                ans+="55";
            }else{
                ans+='5';
                for(int i=0;i<n-2;i++){
                    ans+='9';
                }
                ans+='5';
            }
        }else if(k==8){
            if(n<=6){
                for(int i=0;i<n;i++){
                    ans+='8';
                }
            }else{
                ans+="888";
                for(int i=0;i<n-6;i++){
                    ans+='9';
                }
                ans+="888";
            }
        }else if(k==6){
            if(n==1){
                ans+='6';
            }else if(n==2){
                ans+="66";
            }else{
                ans+='8';
                if((n-2)%2==0){
                    for(int i=0;i<((n-2)/2)-1;i++){
                        ans+='9';
                    }
                    ans+='7';
                    reverse(ans.begin(),ans.end());
                    string s2=ans;
                    reverse(ans.begin(),ans.end());
                    ans+=s2;
                }else{
                    for(int i=0;i<((n-2)/2);i++){
                        ans+='9';
                    }
                    reverse(ans.begin(),ans.end());
                    string s2=ans;
                    reverse(ans.begin(),ans.end());
                    ans+='8';
                    ans+=s2;
                    
                }
            }
        }else if(k==7){
            
            
            for(int i=0;i<n;i++){
                ans+='9';
            }

            if(n%2==1){
                for(char i='9';i>='0';i--){
                    ans[n/2]=i;
                    if(isDivisibleBy7(ans)){
                        return ans;
                    }
                }
            }else{
                for(char i='9';i>='0';i--){
                    ans[n/2]=i;
                    ans[n/2-1]=i;
                    if(isDivisibleBy7(ans)){
                        return ans;
                    }
                }
            }
            
        }

        

        return ans;
        
    }
};