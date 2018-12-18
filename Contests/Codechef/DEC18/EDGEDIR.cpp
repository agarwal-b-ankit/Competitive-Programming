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
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

set<pair<ll,ll>> edges;

void dfs(vector<vector<ll>> &adj, vector<bool> &vis, ll src, ll par){
    vis[src]=true;
    for(ll ver:adj[src]){
        if(!vis[ver]){
            dfs(adj,vis,ver,src);
        }
    }
    vector<pair<ll,ll> > temp;
    for(ll ver:adj[src]){
        if(ver!=par){
            if(!present(edges, mp(src,ver)) && !present(edges, mp(ver,src)))
                temp.pb(mp(ver,src));
        }
    }
    for(pair<ll,ll> p:temp)
        edges.insert(p);
    if(temp.size()%2==1)
        edges.insert(mp(par,src));
}

int main()
{
	FastIO
	ll t,n,m,i,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<vector<ll>> adj(n+1);
		vector<bool> vis(n+1,false);
		vector<pair<ll,ll> > edge;
		for(i=0;i<m;i++){
            cin>>u>>v;
            edge.pb(mp(u,v));
            adj[u].pb(v);
            adj[v].pb(u);
		}
		dfs(adj,vis,1,0);
		if(m%2==1 || present(edges,mp(0,1))){
            cout<<"-1\n";
		} else{
		    for(pair<ll,ll> p: edge){
                if(present(edges,p)) cout<<"0 "; else cout<<"1 ";
		    }
		    cout<<"\n";
		}
		edges.clear();
	}
	return 0;
}
