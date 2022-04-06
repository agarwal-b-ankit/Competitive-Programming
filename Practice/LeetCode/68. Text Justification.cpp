class Solution {
private:
    string justifyLine(vector<string>& words, int maxWidth) {
        if(words.size()==1){
            string ans=words[0];
            for(int i=ans.size();i<maxWidth;i++) ans+=" ";
            return ans;
        }
        
        int totCharacters = 0;
        for(string word:words) totCharacters+=word.length();
        int numSpaces = (maxWidth-totCharacters)/(words.size()-1);
        int remSpaces = (maxWidth-totCharacters)%(words.size()-1);
        
        string space="";
        for(int i=0;i<numSpaces;i++) space+=" ";
        
        string ans = "";
        for(int i = 0;i<words.size();i++, remSpaces--){
            if(i==words.size()-1) ans+=words[i];
            else ans+=words[i]+space + (remSpaces>0?" ":"");
        }
        return ans;
    }
    
    string getLastLine(vector<string>& words, int maxWidth){
        string ans = "";
        for(int i = 0;i<words.size();i++){
            if(i==words.size()-1) ans+=words[i];
            else ans+=words[i]+" ";
        }
        for(int i=ans.size();i<maxWidth;i++)
            ans+=" ";
        return ans;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int width=-1;
        vector<string> ans, temp;
        for(string word:words){
            if(width+1+word.length()>maxWidth){
                ans.push_back(justifyLine(temp, maxWidth));
                temp.clear();
                width=-1;
            }
            temp.push_back(word);
            width+=(1+word.length());
        }
        ans.push_back(getLastLine(temp, maxWidth));
        return ans;
    }
};