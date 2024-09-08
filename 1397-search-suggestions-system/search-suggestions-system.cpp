class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      vector<vector<string>>ans;
      for(int i=0;i<searchWord.size();i++)  {
        set<string>helper;
        for(int j=0;j<products.size();j++){
        int start=0,end=i;
            if(end-start+1>products[j].size()) continue;
            else{
                bool include=true;
                while(start<=end){
                    if(products[j][start]!=searchWord[start]) {
                        include=false;
                        break;
                    }
                    start++;
                }
                if(include) {
                    helper.insert(products[j]);}
            }
        }
        vector<string>tempans;
        int count=3;
        for(auto it=helper.begin();it!=helper.end();it++){
            if(count) tempans.push_back(*it);
            else break;
            count--;
        }
        ans.push_back(tempans);
      }
    return ans;
    }
};