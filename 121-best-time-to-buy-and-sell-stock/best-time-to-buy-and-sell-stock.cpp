class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sell = prices[0];
        int buy = prices[0];

        int profit = 0;

        for(int i = 0; i < n; i++){
            if(prices[i] < buy){
                buy = prices[i];
                sell = prices[i];
            }
            else if(prices[i] > sell){
                sell = prices[i];
                profit = max(sell - buy, profit);
            }
        }

        return profit;
    }
};