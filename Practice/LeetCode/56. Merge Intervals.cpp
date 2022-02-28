class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2){
        if(v1[0]==v2[0]) return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), comp);
        vector<vector<int>> ans;
        for(auto curr:intervals){
            if(ans.size()==0){
                ans.push_back(curr);
                continue;
            }
            vector<int>& prev = ans[ans.size()-1];
            if(curr[0] > prev[1]) ans.push_back(curr);
            else if(curr[1]>prev[1]){
                prev[1]=curr[1];
                //ans[ans.size()-1][1]=curr[1];
            }
        }
        return ans;
    }
};