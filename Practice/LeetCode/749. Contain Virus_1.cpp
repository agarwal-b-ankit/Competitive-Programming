class Solution {
private:
    int find(vector<vector<int>>& a, int i, int j, vector<vector<bool>>& vis){
        if(i<0 || i>=a.size() || j<0 || j>=a[i].size() || a[i][j]==-1 || a[i][j]==2) return 0;
        else if(a[i][j]==0){
            if(!vis[i][j]){
                vis[i][j]=true;
                return 1;
            }
            return 0;
        }
        a[i][j]=2;
        int cnt=0;
        cnt+=find(a,i-1,j,vis);
        cnt+=find(a,i,j-1,vis);
        cnt+=find(a,i,j+1,vis);
        cnt+=find(a,i+1,j,vis);
        return cnt;
    }
    
    int putWalls(vector<vector<int>>& a, int i, int j){
        if(i<0 || i>=a.size() || j<0 || j>=a[i].size() || a[i][j]==-1) return 0;
        else if(a[i][j]==0) return 1;
        a[i][j]=-1;
        int walls=0;
        walls+=putWalls(a,i-1,j);
        walls+=putWalls(a,i,j-1);
        walls+=putWalls(a,i,j+1);
        walls+=putWalls(a,i+1,j);
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
                        vector<vector<bool>> vis(isInfected.size(),vector<bool>(isInfected[0].size(),false));
                        int cnt = find(isInfected, i,j,vis);
                        if(cnt>maxCnt){
                            maxCnt=cnt;
                            maxPos={i,j};
                        }
                    }
                }
            }
            if(maxCnt==0) break;
            walls+=putWalls(isInfected,maxPos.first,maxPos.second);
            spread(isInfected);
        }
        return walls;
    }
};