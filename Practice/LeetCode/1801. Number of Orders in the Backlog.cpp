#define MOD 1000000007
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>> buy;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell;
        for(auto order:orders){
            if(order[2]==0){
                int amount = order[1];
                while(!sell.empty() && sell.top().first<=order[0] && amount>0){
                    if(sell.top().second<=amount){
                        amount-=sell.top().second;
                        sell.pop();
                    } else{
                        int price = sell.top().first;
                        int remaining = sell.top().second-amount;
                        sell.pop();
                        sell.push({price,remaining});
                        amount=0;
                    }
                }
                if(amount>0) buy.push({order[0],amount});
            } else{
                int amount = order[1];
                while(!buy.empty() && buy.top().first>=order[0] && amount>0){
                    if(buy.top().second<=amount){
                        amount-=buy.top().second;
                        buy.pop();
                    } else{
                        int price = buy.top().first;
                        int remaining = buy.top().second-amount;
                        buy.pop();
                        buy.push({price,remaining});
                        amount=0;
                    }
                }
                if(amount>0) sell.push({order[0],amount});
            }
        }
        long ans=0;
        while(!buy.empty()){
            ans+=buy.top().second;
            ans%=MOD;
            buy.pop();
        }
        while(!sell.empty()){
            ans+=sell.top().second;
            ans%=MOD;
            sell.pop();
        }
        return ans;
    }
};