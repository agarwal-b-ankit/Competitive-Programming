class Solution {
public:
    bool isDigit(char c){
        return c>='0' && c<='9';
    }
    int myAtoi(string s) {
        bool negative=false;
        int i=0;
        // ignore leading spaces
        for(;i<s.size();i++)
            if(s[i]!=' ') break;
        
        if(i==s.size()) return 0;
        if(s[i]=='-'){
            negative=true;
            i++;
        } else if(s[i]=='+'){
            i++;
        }
        long ans = 0,cnt=0;
        for(;i<s.size();i++){
            if(!isDigit(s[i])) break;
            int curr=s[i]-'0';
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && curr>INT_MAX%10)){
                if(negative) return INT_MIN;
                else return INT_MAX;
            }
            ans=ans*10+curr;
        }
        if(negative) ans*=-1;
        return ans;
    }
};