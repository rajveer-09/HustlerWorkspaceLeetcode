class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char>mp;

        int counter=0;

        int idx=0;

        while(idx < key.length())
        {
           if(key[idx]==' ')
           {
              idx++;
           }
           else if((key[idx]>='a' and key[idx]<='z') and mp.find(key[idx])==mp.end())
           {
              char ch = char('a' + counter);
              char substitute = key[idx];

              mp[substitute]=ch;

              idx++;
              counter++;
           } 
           else if(mp.find(key[idx]) != mp.end())
           {
               idx++;
           }
        } 

        string ans="";
        for(int i=0;i<message.length();i++)
        {
           if(message[i]==' ')
           {
              ans.push_back(' ');	
           }
           else if(message[i]>='a' and message[i]<='z')
           {
              ans.push_back(mp[message[i]]);
           }
        }
        return ans;
    }
};