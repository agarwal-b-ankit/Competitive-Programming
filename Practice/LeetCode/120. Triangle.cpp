class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            ans=INT_MAX;
            for(int j=0;j<triangle[i].size();j++){
                if(j-1>=0 && j<i) triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
                else if(j-1>=0) triangle[i][j]+=triangle[i-1][j-1];
                else triangle[i][j]+=triangle[i-1][j];
                ans=min(ans,triangle[i][j]);
            }
        }
        return ans;
    }
};