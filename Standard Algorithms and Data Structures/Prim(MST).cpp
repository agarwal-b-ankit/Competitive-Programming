#include <bits/stdc++.h>
using namespace std;
// uncomment for using ordered set provided by GNU++ library
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define present(m,v) (m.find(v)!=m.end())
#define mod 1000000007
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
ll INF=numeric_limits<ll>::max();
const ll MAXN=100010;

ll par[MAXN];
vector<pair<ll,ll>> adj[MAXN];

ll prim(ll src, ll n){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<bool> vis(n,false);
    fill(par,par+MAXN,-1);
    pq.push({0,src});
    ll cost=0;
    while(!pq.empty()){
        ll u=pq.top().ss;
        ll c=pq.top().ff;
        pq.pop();
        if(vis[u]) continue;
        cost+=c;
        vis[u]=true;
        for(auto &v:adj[u]){
            if(!vis[v.ff]){
                par[v.ff]=u;
                pq.push({v.ss,v.ff});
            }
        }
    }
    return cost;
}

void addEdge(ll u, ll v, ll w){
    adj[u].pb({v,w});
    adj[v].pb({u,w});
}

int main()
{
	//FastIO
	ll t,n,i;
	n=9;
	addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
	cout<<"Weight of MST is "<<prim(0,n)<<endl;
	for(i=1;i<n;i++) cout<<i<<" "<<par[i]<<endl;
	return 0;
}
