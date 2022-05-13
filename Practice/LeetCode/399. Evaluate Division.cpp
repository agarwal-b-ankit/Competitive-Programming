class Solution {
private:
    unordered_map<string, vector<pair<string,double>>> graph;
    unordered_map<string,bool> vis;
    double ans;
    
    bool dfs(string start, string end, double product){
        if(start==end){
            ans=product;
            return true;
        }
        vis[start]=true;
        bool temp=false;
        for(auto edge:graph[start]){
            if(vis[edge.first]) continue;
            temp = dfs(edge.first, end, product*edge.second);
            if(temp) break;
        }
        vis[start]=false;
        return temp;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            vis[equations[i][0]]=false;
            vis[equations[i][1]]=false;
        }
        vector<double> result;
        for(auto query:queries){
            ans=1;
            if(graph.find(query[0])==graph.end() || !dfs(query[0],query[1],1)) result.push_back(-1);
            else result.push_back(ans);
        }
        return result;
    }
};