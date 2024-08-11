class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& c) {
        int p=0, q=0;
        for(int i=0;i<c.size();i++){
            if(c[i]=="RIGHT") p++;
            if(c[i]=="DOWN") q++;
            if(c[i]=="UP") q--;
            if(c[i]=="LEFT") p--;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==q && j==p) return ans;
                ans++;
            }
        }
        return ans;
    }
};