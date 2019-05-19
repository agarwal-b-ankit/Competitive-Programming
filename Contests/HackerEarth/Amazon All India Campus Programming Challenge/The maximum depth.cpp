#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main(){
    ll n,query,i,u,v,lev=0;
    cin>>n>>query;
    vector<vector<ll>> graph(n+1),level(n+1);
    vector<ll> a(n+1);
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<n;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n+1);
    vis[1]=true;
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll siz=q.size();
        while(siz--){
            ll val=q.front();
            level[lev].push_back(a[val]);
            q.pop();
            for(auto e:graph[val]){
                if(!vis[e]){
                    vis[e]=true;
                    q.push(e);
                }
            }
        }
        lev++;
    }
    for(i=0;i<=n;i++)
        sort(level[i].begin(),level[i].end());
    ll l,x;
    while(query--){
        cin>>l>>x;
        l=l%lev;
        ll pos=lower_bound(level[l].begin(),level[l].end(),x)-level[l].begin();
        if(pos==level[l].size())
            cout<<"-1\n";
        else cout<<level[l][pos]<<"\n";
    }
    return 0;
}