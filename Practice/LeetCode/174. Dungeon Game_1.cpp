class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)
                    dp[i][j]=1-dungeon[i][j];
                else if(i==n-1)
                    dp[i][j]=dp[i][j+1]-dungeon[i][j];
                else if(j==m-1)
                    dp[i][j]=dp[i+1][j]-dungeon[i][j];
                else
                    dp[i][j]=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                if(dp[i][j]<=0) dp[i][j]=1;
                else dp[i][j]=abs(dp[i][j]);
            }
        }
        return dp[0][0];
    }
};