int dp[101][10001];
class Solution {
public:
    int numSquares(int n) {
        int sqRoot = sqrt(n);
        for(int i = 1;i<=sqRoot;i++){
            for(int j = 1;j<=n;j++){
                dp[i][j]=j/(i*i)+dp[i-1][j%(i*i)];
                if(i>1) dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
        }
        return dp[sqRoot][n];
    }
};