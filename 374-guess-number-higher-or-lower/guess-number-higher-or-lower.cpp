/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s=0;
        int e=n;
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int pick=guess(mid);
            if(pick==0)
            {
              ans=mid;
                break;
            }
            else if(pick==-1)
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};