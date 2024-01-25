class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                s.push_back('[');
                s.push_back('.');
                s.push_back(']');

                // or use s+="[.]"
            } 
            else
            s.push_back(address[i]);
        }

        return s;
    }
};