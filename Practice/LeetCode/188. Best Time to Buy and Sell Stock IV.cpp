class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> profit(prices.size()+1,vector<int>(k+1,0));
        for(int j=1;j<=k;j++){
            int buy=INT_MAX,sell=0;
            for(int i=1;i<=prices.size();i++){
                buy = min(buy, prices[i-1]-profit[i-1][j-1]);
                sell = max(sell,prices[i-1]-buy);
                profit[i][j]=max(profit[i-1][j],sell);
            }
        }
        return profit[prices.size()][k];
    }
};