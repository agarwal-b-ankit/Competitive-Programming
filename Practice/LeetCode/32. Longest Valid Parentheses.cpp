class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size()+1,0);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i==0 || s[i]=='(') continue;
            if(s[i-1]=='(') 
                dp[i+1]=dp[i-1]+2;
            if(i-dp[i]-1>=0 && s[i-dp[i]-1]=='(')
                dp[i+1]=dp[i]+2+dp[i-dp[i]-1];
            ans=max(ans,dp[i+1]);
        }
        return ans;
    }
};