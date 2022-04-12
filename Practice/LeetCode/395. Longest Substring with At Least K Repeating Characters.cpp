class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans=0;
        int freq[26];
        for(int unique=1; unique<=26; unique++){
            memset(freq, 0, sizeof(freq));
            int start=0,end=0,cntu=0,cntk=0;
            while(end<s.size()){
                if(cntu<=unique){ // expand window
                    int ind = s[end]-'a';
                    if(freq[ind]==0) cntu++;
                    freq[ind]++;
                    if(freq[ind]==k) cntk++;
                    end++;
                } else{ // shrink window
                    int ind = s[start]-'a';
                    if(freq[ind]==k) cntk--;
                    freq[ind]--;
                    if(freq[ind]==0) cntu--;
                    start++;
                }
                if(cntu==unique && cntu==cntk)
                    ans=max(ans,end-start);
            }
        }
        return ans;
    }
};