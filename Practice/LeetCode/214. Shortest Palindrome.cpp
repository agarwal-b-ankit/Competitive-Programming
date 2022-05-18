class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string pat= s + "#" + rev;
        // KMP on pat to find longest prefix suffix, this will be the max palindrome in s
        int i=1,len=0, lps[2*s.length()+1];
        lps[0]=0;
        while(i<pat.length()){
            if(pat[i]==pat[len])
                lps[i++]=++len;
            else if(len!=0)
                len=lps[len-1];
            else
                lps[i++]=0;
        }
        int maxPalindromeLen = lps[2*s.length()];
        return rev.substr(0,s.length()-maxPalindromeLen)+s;
    }
};