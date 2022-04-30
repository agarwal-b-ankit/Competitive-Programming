class Solution {
private:
    int dfs(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>>& dp){
        if(i<0 || j<0 || i==matrix.size() || j==matrix[i].size() || matrix[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a1=dfs(matrix,i-1,j,matrix[i][j],dp);
        int a2=dfs(matrix,i+1,j,matrix[i][j],dp);
        int a3=dfs(matrix,i,j+1,matrix[i][j],dp);
        int a4=dfs(matrix,i,j-1,matrix[i][j],dp);
        return dp[i][j]=1+max(max(a1,a2),max(a3,a4));
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                ans=max(ans,dfs(matrix,i,j,INT_MIN, dp));
            }
        }
        return ans;
    }
};