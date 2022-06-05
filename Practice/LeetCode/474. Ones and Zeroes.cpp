int dp[601][101][101];
class Solution {
private:
    pair<int,int> countOnes(string s){
        int cnt=0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='0') cnt++;
        return {cnt,s.size()-cnt};
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=1;i<=strs.size();i++){
            pair<int,int> cnt = countOnes(strs[i-1]);
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(j-cnt.first>=0 && k-cnt.second>=0)
                        dp[i][j][k]=max(dp[i-1][j][k],1+dp[i-1][j-cnt.first][k-cnt.second]);
                    else dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};