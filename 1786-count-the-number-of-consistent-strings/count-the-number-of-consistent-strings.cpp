class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        int arr[26]={0};
        int s=allowed.size();
        for(int i=0;i<s;i++){
            arr[allowed[i]-'a']++;
        }
        int n=words.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<words[i].size();j++){
                if(arr[words[i][j]-'a']==0){
                    flag=false;
                    break;
                }
            }
            if(flag==true) count++;
        }
        return count;
    }
};