class Solution {
private:
    int getMask(string word){
        int freq[26]={0};
        for(char c:word) freq[c-'a']++;
        int mask=0;
        for(int i=0;i<26;i++)
            if(freq[i]>0) mask|=(1<<i);
        return mask;
    }
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask;
        for(auto word:words)
            mask.push_back(getMask(word));
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((mask[i] & mask[j]) == 0)
                    ans=max(ans,(int)(words[i].length()*words[j].length()));
            }
        }
        return ans;
    }
};