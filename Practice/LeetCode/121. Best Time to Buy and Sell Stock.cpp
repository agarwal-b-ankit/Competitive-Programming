class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,buy=INT_MAX;
        for(auto price:prices){
            profit=max(profit,price-buy);
            buy=min(buy,price);
        }
        return profit;
    }
};