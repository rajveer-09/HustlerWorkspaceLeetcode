class Solution {
    public int check(int mid, int[] piles, int h){
        int ans = 0;

        for(int i = 0; i < piles.length; i++){
            ans += piles[i] / mid;
            if(piles[i] % mid != 0){
                ans += 1;
            }

            if(ans > h) return 0;
        }

        return 1;


    }
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int maxValue = piles[0];

        for(int i = 0;  i< piles.length; i++){
            if(piles[i] > maxValue){
                maxValue = piles[i];
            }
        }

        int right = maxValue;

        int ans = -1;


        while(left <= right){
            int mid = left + (right - left) / 2;

            int flg = check(mid, piles, h);

            if(flg == 0){
               left = mid + 1;
            }
            else{
                ans = mid;
                right = mid - 1;
            }


        }


        return ans;
    }
}