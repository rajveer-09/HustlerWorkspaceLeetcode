class Solution {
    public int maxProfit(int[] prices) {
        int m_profit=0;

        for(int i=0;i<prices.length-1;i++){
            if(prices[i+1]>prices[i]){
                for(int j=i+1;j<prices.length;j++){
                    if(prices[j]<prices[i]) break;
                    if((prices[j]-prices[i])>m_profit){
                        m_profit=prices[j]-prices[i];
                    }
                }
            }
            
        }
        return m_profit;
    }
}