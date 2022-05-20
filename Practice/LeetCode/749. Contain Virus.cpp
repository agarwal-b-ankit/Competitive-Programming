class Solution {
private:
    int find(vector<vector<int>>& a, pair<int,int> cell){
        vector<vector<bool>> vis(a.size(),vector<bool>(a[0].size(),false));
        int row[4]={-1,0,0,1},col[4]={0,-1,1,0};
        queue<pair<int,int>> q;
        a[cell.first][cell.second]=2;
        q.push(cell);
        int cnt=0;
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ni=curr.first+row[i],nj=curr.second+col[i];
                if(ni>=0 && ni<a.size() && nj>=0 && nj<a[ni].size()){
                    if(a[ni][nj]==0 && !vis[ni][nj]){
                        vis[ni][nj]=true;
                        cnt++;
                    } else if(a[ni][nj]==1){
                        a[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return cnt;
    }
    
    int putWalls(vector<vector<int>>& a, pair<int,int> cell){
        int row[4]={-1,0,0,1},col[4]={0,-1,1,0};
        queue<pair<int,int>> q;
        a[cell.first][cell.second]=-1;
        q.push(cell);
        int walls=0;
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ni=curr.first+row[i],nj=curr.second+col[i];
                if(ni>=0 && ni<a.size() && nj>=0 && nj<a[ni].size()){
                    if(a[ni][nj]==2){
                        a[ni][nj]=-1;
                        q.push({ni,nj});
                    } else if(a[ni][nj]==0) walls++;
                }
            }
        }
        return walls;
    }
    
    void spread(vector<vector<int>>& a){
        int row[4]={-1,0,0,1},col[4]={0,-1,1,0};
        queue<pair<int,int>> q;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]==2){
                    a[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ni=curr.first+row[i],nj=curr.second+col[i];
                if(ni>=0 && ni<a.size() && nj>=0 && nj<a[ni].size() && a[ni][nj]==0){
                    a[ni][nj]=1;
                }
            }
        }
    }
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int walls=0;
        while(true){
            int maxCnt=0;
            pair<int,int> maxPos;
            for(int i=0;i<isInfected.size();i++){
                for(int j=0;j<isInfected[i].size();j++){
                    if(isInfected[i][j]==1){
                        int cnt = find(isInfected, {i,j});
                        if(cnt>maxCnt){
                            maxCnt=cnt;
                            maxPos={i,j};
                        }
                    }
                }
            }
            if(maxCnt==0) break;
            walls+=putWalls(isInfected,maxPos);
            spread(isInfected);
        }
        return walls;
    }
};