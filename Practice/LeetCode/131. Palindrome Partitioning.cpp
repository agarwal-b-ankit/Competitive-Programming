class Solution {
public:
    bool isPalindrome(string s){
        for(int i=0;i<=s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }
    
    void partition(string s, int ind, vector<vector<string>> dp[], vector<bool> vis) {
        if(vis[ind]) return;
        vis[ind]=true;
        vector<vector<string>> vec;
        string st;
        for(int i=ind;i<s.size();i++){
            st+=s[i];
            if(isPalindrome(st)){
                if(i+1==s.size()){
                    vector<string> temp{st};
                    vec.push_back(temp);
                } else{
                    partition(s,i+1, dp, vis);
                    for(auto v:dp[i+1]){
                        v.insert(v.begin(),st);
                        vec.push_back(v);
                    }
                }
            }
        }
        dp[ind]=vec;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> dp[16];
        vector<bool> vis(16,false);
        partition(s,0, dp, vis);
        return dp[0];
    }
};