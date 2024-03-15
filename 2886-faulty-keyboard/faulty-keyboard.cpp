class Solution {
public:
    string finalString(string s) {
        string result="";
        for( auto i: s){
          if(i =='i'){
            reverse(result.begin(), result.end()); 
            }
          result+=i;
        } result.erase(  remove(result.begin(), result.end(), 'i')  , result.end()  );
        return result;
    }};