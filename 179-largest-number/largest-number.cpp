//very very important question
class Solution {
public:
 static bool mycomp(string a,string b){
     string t1=a+b;
     string t2=b+a;
     return t1>t2;
 }
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(to_string(nums[i]));
        }        
        sort(temp.begin(),temp.end(),mycomp);
        if(temp[0]=="0"){
            return "0";
        }
        string ans="";
        for(auto it:temp){
            ans+=it;
        }
        return ans;
    }
};