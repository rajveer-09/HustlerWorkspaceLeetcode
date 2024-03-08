class Solution {
    public int maxProfit(int[] prices) {
        int mini=prices[0];
        int cost=0,maxprofit=0;
        for(int i=0;i<prices.length;i++)
        {
            cost=prices[i]-mini;
            maxprofit=Math.max(maxprofit,cost);
            mini=Math.min(mini,prices[i]);
        }
        return maxprofit;
    }
}