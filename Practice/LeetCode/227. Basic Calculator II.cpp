class Solution {
public:
    int calculate(string s) {
        int curr=0;
        char operation='+';
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9')
                curr=curr*10+(s[i]-'0');
            if(!(s[i]>='0' && s[i]<='9') && s[i]!=' ' || i==s.length()-1){
                if(operation=='+'){
                    st.push(curr);
                } else if(operation=='-'){
                    st.push(-curr);
                } else if(operation=='*'){
                    int val = st.top()*curr;
                    st.pop();
                    st.push(val);
                } else if(operation=='/'){
                    int val = st.top()/curr;
                    st.pop();
                    st.push(val);
                }
                operation=s[i];
                curr=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};