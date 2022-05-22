class Solution {
public:
    int calculate(string s) {
        int result=0,sign=1;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            } else if(s[i]==')'){
                result = result*st.top();
                st.pop();
                result+=st.top();
                st.pop();
                sign=1;
            } else if(s[i]=='+'){
                sign=1;
            } else if(s[i]=='-'){
                sign=-1;
            } else if(s[i]>='0' && s[i]<='9'){
                int num=s[i]-'0';
                while(i+1<s.size() && s[i+1]>='0' && s[i+1]<='9'){
                    num=num*10+(s[++i]-'0');
                }
                result+=num*sign;
            }
        }
        return result;
    }
};