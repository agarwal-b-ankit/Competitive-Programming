class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        for(int len=1;len<=s.length();len++){
            for(int i=0,j=len-1;j<s.size();i++,j++){
                if(i==j) dp[i][j]=1;
                else if(s[i]==s[j])
                    dp[i][j]=2+((j-i>1)?dp[i+1][j-1]:0);
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][s.length()-1];
    }
};