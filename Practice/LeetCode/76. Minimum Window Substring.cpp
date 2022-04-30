class Solution {
public:
    string minWindow(string s, string t) {
        int required=0,cnt=s.length()+1,aleft=-1,aright=-1;
        int freq[60];
        memset(freq,0,sizeof(freq));
        for(char c:t) freq[c-'A']++;
        for(int i=0;i<60;i++) if(freq[i]>0) required++;
        for(int left=0,right=0;right<s.size();right++){
            freq[s[right]-'A']--;
            if(freq[s[right]-'A']==0) required--;
            while(required==0){
                if(cnt>right-left+1){
                    cnt=right-left+1;
                    aleft=left;
                    aright=right;
                }
                freq[s[left]-'A']++;
                if(freq[s[left]-'A']==1) required++;
                left++;
            }
        }
        if(aleft==-1) return "";
        return s.substr(aleft,aright-aleft+1);
    }
};