class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0) q.push({i,j});
            }
        }
        vector<vector<int>> dist(mat.size(),vector<int>(mat[0].size(),-1));
        int level=-1;
        int row[4]={-1,0,0,1},col[4]={0,-1,1,0};
        while(!q.empty()){
            int cnt=q.size();
            level++;
            while(cnt--){
                pair<int,int> curr = q.front();
                q.pop();
                dist[curr.first][curr.second]=level;
                for(int i=0;i<4;i++){
                    int ni=curr.first+row[i],nj=curr.second+col[i];
                    if(ni>=0 && ni<mat.size() && nj>=0 && nj<mat[ni].size() && mat[ni][nj]==1){
                        mat[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return dist;
    }
};