class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> palindrome(s.length(),vector<bool>(s.length(),false));
        vector<int> dp(s.length(),INT_MAX);
        for(int i=0;i<s.length();i++){
            for(int j=i;j>=0;j--){
                if(s[i]==s[j]){
                    if (j+1<=i-1) palindrome[j][i]=palindrome[j+1][i-1];
                    else palindrome[j][i]=true;
                }
                if(palindrome[j][i]){
                    if(j==0) dp[i]=0;
                    else if(dp[j-1]!=INT_MAX) dp[i]=min(dp[i],dp[j-1]+1);
                }
            }
        }
        return dp[s.length()-1];
    }
};