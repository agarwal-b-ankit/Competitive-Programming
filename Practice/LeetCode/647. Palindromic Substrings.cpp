class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int len=0;len<=i;len++){
                if(i+len<s.size() && i-len>=0 && s[i+len]==s[i-len]){
                    ans++;
                } else break;
            }
            for(int len=0;len<=i;len++){
                if(i+len+1<s.size() && i-len>=0 && s[i+len+1]==s[i-len]){
                    ans++;
                } else break;
            }
        }
        return ans;
    }
};