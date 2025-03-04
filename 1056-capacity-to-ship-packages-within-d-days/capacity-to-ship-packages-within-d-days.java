class Solution {
    public int check(int mid, int[] arr, int d){
        int day = 1;
        int sum = 0;

        for(int i = 0; i < arr.length; i++){
            if(sum + arr[i] > mid){
                day++;
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }

            if(day > d){
                return 1;
            }
        }

        return 0;
               
    }
    public int shipWithinDays(int[] weights, int days) {
        int maxi = weights[0];

        for(int wt : weights) if(wt > maxi) maxi = wt;

        int low = maxi;

        int sum = 0;

        for(int wt : weights){
            sum += wt;
        }

        int high = sum;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int flg = check(mid, weights, days);

            if(flg == 0){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
}