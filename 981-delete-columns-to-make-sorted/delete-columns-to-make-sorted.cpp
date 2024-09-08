class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
      ios_base::sync_with_stdio(false);
      int count=0;
      for(int i=0;i<strs[0].size();i++)
      {
        vector<int>v;
        for(int j=0;j<strs.size();j++)
        {
            v.push_back(strs[j][i]-'a');
        }
        vector<int>v1=v;
        sort(v1.begin(),v1.end());
        for(int k=0;k<v.size();k++)
        {
            if(v1[k]!=v[k])
            {
                count++;
                break;
            }
        }
      }  
      return count;
    }
};