class Solution {
private:
    bool dfs(int source, vector<vector<int>>& graph, vector<int>& vis){
        if(vis[source]!=0) return vis[source]==2;
        vis[source]=1;
        for(int destination: graph[source]){
            if(vis[destination]==2) continue;
            if(vis[destination]==1 || !dfs(destination, graph, vis)) return false;
        }
        vis[source]=2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<int> result;
        for(int i=0;i<graph.size();i++){
            if(dfs(i, graph, vis))
                result.push_back(i);
        }
        return result;
    }
};