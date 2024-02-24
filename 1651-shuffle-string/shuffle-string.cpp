class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret = "";
        vector<char> ch( s.length() );

        for( int i = 0; i < indices.size(); i++ ) {
            ch[ indices[i] ] = s[i];
        }
        
        for( int i = 0; i < ch.size(); i++ ) {
            ret.push_back( ch[i] );
        }

        return ret;
    }
};