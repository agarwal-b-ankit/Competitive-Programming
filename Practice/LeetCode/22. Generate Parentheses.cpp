class Solution {
public:
    vector<string> res;
    int solve(int l, int r, int bal, string str){
        if(l<0 || r<0) return 0;
        else if(l==0 && r==0){
            if(bal==0){
                res.push_back(str);
                return 1;
            } else return 0;
        }
        if(bal==0) return solve(l-1,r,bal+1, str+'(');
        return solve(l-1,r,bal+1,str+'(')+solve(l,r-1,bal-1,str+')');
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n,n,0,"");
        return res;
    }
};