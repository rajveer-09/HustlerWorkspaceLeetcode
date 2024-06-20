class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[3]{0};
        if(bills[0]>5) return false;
        else arr[0]++;
        for(int i=1;i<bills.size();i++){
            if(bills[i]==5) arr[0]++;
            else if(bills[i]==10){
                if(arr[0]==0) return false;
                else{
                    arr[1]++;
                    arr[0]--;
                }
            }
            else if(bills[i]==20){
                if(arr[0]==0) return false;
                else if(arr[1]==0 && arr[0]<3) return false; 
                else{
                    arr[2]++;
                    if(arr[1]){
                        arr[1]--;
                        arr[0]--;
                    }
                    else{
                        arr[0]--;
                        arr[0]--;
                        arr[0]--;
                    } 
                }
            }
        }
        return true;
    }
};