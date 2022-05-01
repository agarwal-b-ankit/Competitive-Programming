bool compare(string s1, string s2){
    return s1+s2>s2+s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int num:nums)
            temp.push_back(to_string(num));
        sort(temp.begin(),temp.end(),compare);
        string ans="";
        for(string st:temp)
            ans+=st;
        if(ans[0]=='0') return "0";
        else return ans;
    }
};