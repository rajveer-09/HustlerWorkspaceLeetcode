class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>hash;
        char ch='a';
        for(int i=0;i<key.size();i++){
            if(key[i]==' ')
            continue;
            if(!hash.count(key[i]))
            hash[key[i]]=ch++;
        }
        for(int i=0;i<message.size();i++){
            if(hash.count(message[i]))
            message[i]=hash[message[i]];
        }
        return message;
    }
};