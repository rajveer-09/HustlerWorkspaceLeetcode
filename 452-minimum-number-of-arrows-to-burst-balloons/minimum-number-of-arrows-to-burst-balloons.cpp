class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
               sort(points.begin(),points.end(),[](vector<int> &v1,vector<int> &v2){
            if(v1[0]==v2[0]){
                return v1[1]<v2[1];
            }
            return v1[0]<v2[0];
        });

       int count=0;  
       int prevlast=points[0][1];
          
       for(int i=1;i<points.size();i++){
           if(prevlast >= points[i][0]){
               if(prevlast >points[i][1]){
                   prevlast=points[i][1];
               
               }
           }else{
               prevlast=points[i][1];
               count++;
           }
       }

       return count+1;

    }
};