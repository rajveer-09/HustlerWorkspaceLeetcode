class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> k;
        for(int i = 0; i < t.size(); i++){
            k[t[i]]++;
        }
        
        int n = s.size();
        int left = 0, right = 0;
        int ans = INT_MAX;
        string result = "";
        int start ;
        int cnt = k.size(); // number of unique chars still needed
        
        while(right < n){
            if(k.find(s[right]) != k.end()){
                k[s[right]]--;
                if(k[s[right]] == 0) cnt--;
            }
            
            while(cnt == 0){
                if(ans > right - left + 1){
                    ans = right - left + 1;
                    start=left;
                }
                if(k.find(s[left]) != k.end()){
                    k[s[left]]++;
                    if(k[s[left]] > 0) cnt++;
                }
                left++;
            }
            right++;
        }
        if(ans==INT_MAX) return "";
        result =s.substr(start,ans);
        return result;
    }
};
