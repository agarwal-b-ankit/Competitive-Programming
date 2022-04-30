class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int a[] = {-1,0,0,1};
        int b[] = {0,-1,1,0};
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==2) q.push({i,j});
        
        int min=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int ni = p.first+a[i];
                    int nj = p.second+b[i];
                    if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[ni].size() && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
            if(q.size()>0) min++;
        }
        
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==1) return -1;
        
        return min;
    }
};