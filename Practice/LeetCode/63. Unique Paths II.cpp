class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& dp) {
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                if(dp[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=dp[i][j-1];
                else if(j==0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};