#define MOD 1000000007
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp) {
        if(fuel<0) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int cnt=(start==finish)?1:0;
        for(int i=0;i<locations.size();i++){
            if(i==start) continue;
            cnt+=countRoutes(locations, i, finish, fuel-abs(locations[i]-locations[start]), dp);
            cnt%=MOD;
        }
        return dp[start][fuel]=cnt;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(101, vector<int>(201,-1));
        return countRoutes(locations, start, finish, fuel, dp);
    }
};