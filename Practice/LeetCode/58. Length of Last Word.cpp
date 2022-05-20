class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,len=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') len=0;
            else len++;
            if(len!=0) ans=len;
        }
        return ans;
    }
};