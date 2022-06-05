class UnionFind{
public:
    vector<int> par, rank;
    UnionFind(int n){
        for(int i=0;i<n;i++){
            par.push_back(i);
            rank.push_back(1);
        }
    }
    
    int find(int u){
        if(par[u]!=u) par[u]=find(par[u]);
        return par[u];
    }
    
    void uni(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            par[pu]=pv;
            rank[pv]+=rank[pu];
        } else{
            par[pv]=pu;
            rank[pu]+=rank[pv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        for(auto connection: connections)
            uf.uni(connection[0],connection[1]);
        int comp=0;
        for(int i=0;i<n;i++)
            if(uf.find(i)==i) comp++;
        if(connections.size()<n-1) return -1;
        return comp-1;
    }
};