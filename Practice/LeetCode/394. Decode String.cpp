class Solution {
private:
    int findClosing(string& s, int ind){
        int bal=1;
        for(int i=ind;i<s.size();i++){
            if(s[i]=='[') bal++;
            else if(s[i]==']') bal--;
            if(bal==0) return i;
        }
        return -1;
    }
    
    string decodeString(string& s, int start, int end) {
        if(start>end) return "";
        if(s[start]>='0' && s[start]<='9'){
            int i=start,num=0;
            while(s[i]>='0' && s[i]<='9')
                num=num*10+(s[i++]-'0');
            int close=findClosing(s,i+1);
            string temp=decodeString(s, i+1, close-1);
            string ans="";
            while(num--) ans+=temp;
            return ans+decodeString(s, close+1, end);
        } else return s[start]+decodeString(s, start+1, end);
    }
public:
    string decodeString(string s) {
        return decodeString(s,0,s.length()-1);
    }
};