class Solution {
public:
    vector<int> adj[100001];
    
    bool hasCycle(int u, vector<bool>& vis, vector<bool>& dfs){
        if(vis[u]) return true;
        if(dfs[u]) return false;
        dfs[u]=true;
        vis[u]=true;
        for(auto v:adj[u]){
            if(hasCycle(v, vis, dfs)) return true;
        }
        vis[u]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,int> m;
        for(auto v:prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> vis(numCourses,false), dfs(numCourses,false);
        for(int i =0;i<numCourses;i++){
            if(!dfs[i] && hasCycle(i, vis, dfs)){
                return false;
            }
        }
        return true;
    }
};