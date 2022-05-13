class Solution {
    vector<pair<int, double>> adj[10001];
    double dist[10001];
private:
    void djikstra(int start){
        for(int i=0;i<10001;i++) dist[i]=INT_MAX;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({1,start});
        while(!pq.empty()){
            pair<double,int> top = pq.top();
            pq.pop();
            for(auto edge:adj[top.second]){
                if(edge.second*top.first<dist[edge.first]){
                    dist[edge.first]=edge.second*top.first;
                    pq.push({dist[edge.first],edge.first});
                }
            }
        }
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], 1/succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], 1/succProb[i]});
        }
        djikstra(start);
        if(dist[end]==INT_MAX) return 0;
        else return 1/dist[end];
    }
};