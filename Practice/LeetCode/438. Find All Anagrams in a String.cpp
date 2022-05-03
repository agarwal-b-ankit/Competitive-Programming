class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()>s.length()) return ans;
        int freq[26]={0},temp[26]={0};
        int required=0;
        for(int i=0;i<p.length();i++){
            freq[p[i]-'a']++;
            if(freq[p[i]-'a']==1) required++;
        }
        for(int i=0;i<p.length()-1;i++){
            temp[s[i]-'a']++;
            if(temp[s[i]-'a']==freq[s[i]-'a']) required--;
        }
        for(int i=p.length()-1,left=0;i<s.size();i++){
            // expand window by 1
            temp[s[i]-'a']++;
            if(temp[s[i]-'a']==freq[s[i]-'a']) required--;
            
            if(required==0) ans.push_back(left);
            
            // shrink window by 1
            if(temp[s[left]-'a']==freq[s[left]-'a']) required++;
            temp[s[left++]-'a']--;
        }
        return ans;
    }
};