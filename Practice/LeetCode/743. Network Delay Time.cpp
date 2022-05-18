class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> graph[n+1];
        vector<int> dist(n+1,INT_MAX);
        for(auto time:times)
            graph[time[0]].push_back({time[1],time[2]});
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            pq.pop();
            for(auto edge: graph[curr.second]){
                if(curr.first+edge.second<dist[edge.first]){
                    dist[edge.first]=curr.first+edge.second;
                    pq.push({dist[edge.first], edge.first});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
            ans=max(ans,dist[i]);
        return (ans==INT_MAX)?-1:ans;
    }
};