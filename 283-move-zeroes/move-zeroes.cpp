class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                temp.push_back(a[i]);
            }
        }
        int z=temp.size();
        for(int i=0;i<z;i++){
            a[i]=temp[i];
        }
        for(int i=z;i<n;i++){
            a[i]=0;
        }
    }
};