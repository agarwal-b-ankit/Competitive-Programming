class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++){
                if(i==0) dp[i][j]+=1;
                for(int k=0;i>0 && k<=j;k++)
                    dp[i][j]+=dp[i-1][k];
                }
        return accumulate(dp[n-1].begin(),dp[n-1].end(),0);
    }
};