class Solution {
private:
	bool solve(string s, int ind, set<string>& wordSet, vector<int>& dp, vector<vector<string>>& store){
		if(dp[ind]!=-1) return dp[ind];
        vector<string> ans;
        for(int i=ind;i<s.size();i++){
			string curr = s.substr(ind,i-ind+1);
            if(wordSet.find(curr)!=wordSet.end()){
                if(i==s.size()-1)
					ans.push_back(curr);
				else if(solve(s,i+1,wordSet, dp, store)){
                    for(string s:store[i+1])
                        ans.push_back(curr+" "+s);
				}
            }
        }
        if(ans.size()>0){
            store[ind]=ans;
			return dp[ind]=true;
        }
        else return dp[ind]=false;
    }
	
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet;
        for(auto e:wordDict)
            wordSet.insert(e);
		vector<int> dp(s.size(),-1);
		vector<vector<string>> store(s.size(), vector<string>(0));
        solve(s,0,wordSet,dp,store);
        return store[0];
    }
};