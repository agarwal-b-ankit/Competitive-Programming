class Solution {
public:
    vector<int> partitionLabels(string s) {
        int right[26]={0};
        for(int i=0;i<s.size();i++)
            right[s[i]-'a']=i;
        vector<int> ans;
        for(int i=0,start=0,end=0;i<s.size();i++){
            end=max(end,right[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};