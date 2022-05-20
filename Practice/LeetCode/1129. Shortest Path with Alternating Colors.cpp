class Solution {
private:
    vector<int> ans;
    void bfs(int n, vector<vector<pair<int,int>>>& graph){
        vector<vector<bool>> vis(n,vector<bool>(2,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        int level=-1;
        while(!q.empty()){
            int cnt = q.size();
            level++;
            while(cnt--){
                pair<int,int> u = q.front();
                q.pop();
                vis[u.first][u.second]=true;
                ans[u.first]=min(ans[u.first],level);
                for(pair<int,int> v:graph[u.first]){
                    if(v.second==u.second || vis[v.first][v.second]) continue;
                    q.push(v);
                }
            }
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        ans = vector<int>(n,INT_MAX);
        vector<vector<pair<int,int>>> graph(n);
        for(auto edge:redEdges)
            graph[edge[0]].push_back({edge[1],0});
        for(auto edge:blueEdges)
            graph[edge[0]].push_back({edge[1],1});
        bfs(n,graph);
        for(int i=0;i<n;i++)
            if(ans[i]==INT_MAX) ans[i]=-1;
        return ans;
    }
};