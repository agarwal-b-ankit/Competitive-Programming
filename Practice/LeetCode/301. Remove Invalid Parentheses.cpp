class Solution {
private:
    unordered_set<string> result;
    int maxLen;
    void solve(string& s, int ind, int left, int right, vector<char>& temp){
        if(ind==s.size()){
            if(left==right){
                if(left>=maxLen){
                    if(left>maxLen) result.clear();
                    result.insert(string(temp.begin(),temp.end()));
                    maxLen=left;
                }
            }
            return;
        }
        if(s[ind]!='(' && s[ind]!=')'){
            temp.push_back(s[ind]);
            solve(s,ind+1,left,right,temp);
            temp.pop_back();
        }
        else{
            solve(s, ind+1,left,right, temp);
            temp.push_back(s[ind]);
            if(s[ind]=='(') solve(s,ind+1,left+1,right,temp);
            else if(left>right) solve(s,ind+1,left,right+1,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<char> temp;
        solve(s, 0, 0, 0,temp);
        return vector<string>(result.begin(),result.end());
    }
};