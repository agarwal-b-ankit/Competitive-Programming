class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> outdegree(graph.size(),0);
        vector<vector<int>> transpose(graph.size());
        vector<int> result;
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0) q.push(i);
            for(int v:graph[i]){
                outdegree[i]++;
                transpose[v].push_back(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(int v:transpose[u]){
                outdegree[v]--;
                if(outdegree[v]==0) q.push(v);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};