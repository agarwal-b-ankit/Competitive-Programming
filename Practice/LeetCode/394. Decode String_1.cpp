class Solution {
public:
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> resSt;
        string res="";
        int num=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9')
                num=num*10+(s[i]-'0');
            else if(s[i]>='a' && s[i]<='z')
                res+=s[i];
            else if(s[i]=='['){
                resSt.push(res);
                res="";
                numSt.push(num);
                num=0;
            } else{
                int cnt=numSt.top();
                string temp="";
                while(cnt--)
                    temp+=res;
                res=resSt.top()+temp;
                resSt.pop();
                numSt.pop();
            }
        }
        return res;
    }
};