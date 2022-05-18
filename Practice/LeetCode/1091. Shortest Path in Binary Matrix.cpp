class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row[8] = {-1,-1,-1,0,0,1,1,1}, col[8] = {-1,0,1,-1,1,-1,0,1};
        queue<pair<int,int>> q;
        if(grid[0][0]!=0) return -1;
        q.push({0,0});
        grid[0][0]=1;
        int pathLen=0;
        while(!q.empty()){
            int cnt = q.size();
            pathLen++;
            while(cnt--){
                pair<int,int> curr = q.front();
                q.pop();
                if(curr.first==grid.size()-1 && curr.second==grid[0].size()-1)
                    return pathLen;
                for(int i=0;i<8;i++)
                        if(row[i]+curr.first>=0 && row[i]+curr.first<grid.size() && col[i]+curr.second>=0 && col[i]+curr.second<grid[0].size() && grid[row[i]+curr.first][col[i]+curr.second]==0){
                            q.push({row[i]+curr.first,col[i]+curr.second});
                            grid[row[i]+curr.first][col[i]+curr.second]=1;
                        }
            }
        }
        return -1;
    }
};