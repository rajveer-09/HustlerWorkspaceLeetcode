class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        int max_profit=0;
        int min_value=prices[0];

        for(int i=0;i<n;i++){
            if(prices[i]<min_value) min_value=prices[i];

            if((prices[i]-min_value)>max_profit){
                max_profit= prices[i]-min_value;
            }
        }
        return max_profit;
    }
}