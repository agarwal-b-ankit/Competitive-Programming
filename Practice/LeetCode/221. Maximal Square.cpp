class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(2,vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int k=i%2;
                dp[k][j]=0;
                if(matrix[i][j]=='0') continue;
                if(i==0 || j==0) dp[k][j]=1;
                else dp[k][j]=1+min(min(dp[k][j-1],dp[1-k][j]),dp[1-k][j-1]);
                ans=max(ans,dp[k][j]);
            };
        }
        return ans*ans;
    }
};