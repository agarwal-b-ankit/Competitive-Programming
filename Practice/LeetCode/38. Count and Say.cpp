class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string st = countAndSay(n-1);
        char prev=st[0];
        int cnt=1;
        string ans = "";
        for(int i=1;i<st.size();i++){
            if(st[i]==prev){
                cnt++;
            } else{
                ans=ans+to_string(cnt)+prev;
                prev=st[i];
                cnt=1;
            }
        }
        ans=ans+to_string(cnt)+prev;
        return ans;
    }
};