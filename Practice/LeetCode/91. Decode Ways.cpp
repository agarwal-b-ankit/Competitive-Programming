class Solution {
public:
    int solve(string s, int ind, vector<int>& dp){
        if(ind==s.size()) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int ans = 0;
        if(s[ind]!='0'){
            ans+=solve(s,ind+1,dp);
            if(s[ind]=='1' && ind+1<s.size())
                ans+=solve(s,ind+2,dp);
            if(s[ind]=='2' && ind+1<s.size() && s[ind+1]>='0' && s[ind+1]<='6')
                ans+=solve(s,ind+2,dp);
        }
        return dp[ind]=ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);
    }
};