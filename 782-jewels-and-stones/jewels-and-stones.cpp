class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int n1= jewels.size();
        int n2= stones.size();

        int cnt =0;

        int arr[256]={0};
        for(int i=0;i<n1;i++){
            arr[jewels[i]]=1;
        }
    
        for(int i=0;i<n2;i++){
            if(arr[stones[i]]!=0) cnt++;
        }

        return cnt;
    }
};