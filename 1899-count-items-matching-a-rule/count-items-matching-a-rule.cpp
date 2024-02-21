class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count=0;
        int keyIndex=0;
        if(ruleKey == "color")
        {                          //  0      1       2
            keyIndex=1; //set index  [typei, colori, namei]  this is a row
        } 
        else if(ruleKey == "name")
        {
            keyIndex=2;
        }
              
        for(size_t i=0;i<items.size();i++)
        {
            if(items[i][keyIndex]==ruleValue)
                count++;
        }
         return count;
    }
};