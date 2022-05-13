class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>> dp(s.length()+1,vector<unsigned int>(t.length()+1,0));
        for(int i=0;i<=s.length();i++)
            dp[i][0]=1;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<t.length();j++){
                if(s[i]==t[j]) dp[i+1][j+1]=dp[i][j+1]+dp[i][j];
                else dp[i+1][j+1]=dp[i][j+1]; 
            }
        }
        return dp[s.length()][t.length()];
    }
};