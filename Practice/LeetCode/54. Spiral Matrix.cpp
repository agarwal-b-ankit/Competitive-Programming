class Solution {
public:
    void solve(vector<vector<int>>& matrix, int i, int j, int dir, vector<int>& ans, pair<int,int> d[]){
        ans.push_back(matrix[i][j]);
        matrix[i][j]=1000;
        for(int k=0;k<4;k++){
            int ni=i+d[dir].first,nj=j+d[dir].second;
            if(ni>=0 && ni<matrix.size() && nj>=0 && nj<matrix[0].size() && matrix[ni][nj]!=1000){
                return solve(matrix,ni,nj,dir,ans,d);
            }
            dir=(dir+1)%4;
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        pair<int,int> d[4] = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> ans;
        solve(matrix, 0, 0, 0, ans, d);
        return ans;
    }
};