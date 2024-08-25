class Solution {
    
public:
   bool check(int num1 , int num2){
       string first  = to_string(num1);
       string second = to_string(num2);
      
       while(first.length() < second.length()) first =  "0" + first;
       while(second.length() < first.length()) second = "0" + second;

       int diff = 0;
       int a = -1 , b= -1;
       for(int i = 0; i<first.length(); i++){
            if(first[i] != second[i]){
                diff++;
                if(diff==1) a = i;
                else if(diff==2) b = i;
                else return false;

             
            }
       }
       if(diff==2){
         swap(first[a] ,first[b]);
       }
       if(first == second) return true;
       
            
      return false;
   }
    
    int countPairs(vector<int>& nums) {
        int count =0; 
        for(int i = 0; i  < nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
               
                if(nums[i] == nums[j] || check(nums[i] , nums[j])) count++;
            }
        }
        
        return count;
    }
};