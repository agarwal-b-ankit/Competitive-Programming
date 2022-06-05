class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> lookup(1<<k,false);
        int num=0, required=1<<k;
        int ones = required-1;
        for(int i=0;i<s.length();i++){
            num= ((num<<1) & ones) | (s[i]-'0');
            if(i>=k-1 && lookup[num]==false){ 
                lookup[num]=true;
                required--;
                if(required==0) return true;
            }
        }
        return false;
    }
};