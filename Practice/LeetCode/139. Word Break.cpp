class Solution {
public:
    bool wordBreak(string s, int ind, set<string>& dict, vector<int>& dp){
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<s.size();i++){
            if(dict.find(s.substr(ind,i-ind+1))!=dict.end()){
                if(i==s.size()-1 || wordBreak(s,i+1,dict, dp)){
                    dp[ind]=true;
                    return true;
                }
            }
        }
        return dp[ind]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(auto e:wordDict)
            dict.insert(e);
        vector<int> dp(s.size(),-1);
        return wordBreak(s,0,dict,dp);
    }
};