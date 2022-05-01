class Solution {
public:
    int calculate(string s) {
        int ans=0,prev=0,curr=0;
        char operation='+';
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9')
                curr=curr*10+(s[i]-'0');
            if(!(s[i]>='0' && s[i]<='9') && s[i]!=' ' || i==s.length()-1){
                if(operation=='+'){
                    ans+=prev;
                    prev=curr;;
                } else if(operation=='-'){
                    ans+=prev;
                    prev=-curr;
                } else if(operation=='*'){
                    prev*=curr;
                } else if(operation=='/'){
                    prev/=curr;
                }
                operation=s[i];
                curr=0;
            }
        }
        ans+=prev;
        return ans;
    }
};