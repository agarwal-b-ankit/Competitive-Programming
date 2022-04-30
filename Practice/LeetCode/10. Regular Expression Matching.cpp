class Solution {
private:
    bool isMatch(string s, int i, string p, int j, vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==p.size()){
            return dp[i][j]=(i==s.size());
        }
        bool ans = false;
        if(j+1<p.size() && p[j+1]=='*'){
            ans=isMatch(s,i,p,j+2, dp);
            if(i<s.size() && (p[j]=='.' || p[j]==s[i])){
                ans = ans || isMatch(s,i+1,p,j, dp);
            }
        } else if(i<s.size() && (p[j]=='.' || p[j]==s[i])){
            ans=isMatch(s,i+1,p,j+1, dp);
        }
        return dp[i][j]=ans;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return isMatch(s,0,p,0,dp);
    }
};