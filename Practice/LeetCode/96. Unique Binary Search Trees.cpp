class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1,sum=0;i<=n;i++)
            for(int j=0;j<i;j++)
                dp[i]+=dp[j]*dp[i-j-1];
        return dp[n];
    }
};