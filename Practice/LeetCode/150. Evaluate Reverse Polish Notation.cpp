class Solution {
public:
    bool isOperator(string token){
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    int operate(int v1, int v2, string token){
        if(token == "+") return v1+v2;
        else if(token == "-") return v1-v2;
        else if(token == "*") return v1*v2;
        else return v1/v2;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token:tokens){
            if(isOperator(token)){
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                st.push(operate(val1, val2, token));
            } else st.push(stoi(token));
        }
        return st.top();
    }
};