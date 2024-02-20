class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0;
        int end=letters.size()-1;
        int pos=0;
        int flag=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(letters[mid]==target){
                pos=mid+1;
                start=mid+1;
                flag=1;
            }
            else if(letters[mid]>target) end=mid-1;
            else start=mid+1;
        }
        if(flag==0) pos=start;
        if(pos==letters.size()) return letters[0];
        return letters[pos];
    }
};