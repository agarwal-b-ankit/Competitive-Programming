class Solution {
public:
    vector<vector<int>> dp;
    Solution(): dp(101,vector<int>(101,-1)) {};
    int uniquePaths(int m, int n) {
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(m<1 || n<1) return 0;
        else if(m==1 && n==1) return 1;
        else return dp[m][n]=uniquePaths(m-1,n)+uniquePaths(m,n-1); 
    }
};