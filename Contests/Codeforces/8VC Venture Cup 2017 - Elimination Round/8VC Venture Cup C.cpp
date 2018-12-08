#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define present(m,v) (m.find(v)!=m.end())
#define INF 1e18
#define mod 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)

ll dfs(vector<vector<ll> > &adj, vector<bool> &vis, ll st)
{
    vis[st]=true;
    ll siz=1;
    for(ll i:adj[st])
        if(!vis[i])
            siz+=dfs(adj,vis,i);
    return siz;
}

ll dfsV(vector<vector<ll> > &adj)
{
    vector<bool> vis(adj.size(),false);
    ll ans=0;
    vector<ll> vec;
    for(ll i=0;i<adj.size();i++)
    {
        if(!vis[i])
        {
            ll siz=dfs(adj,vis,i);
            ans++;
        }
    }
    return ans;
}

int main()
{
	ll n,p;
	cin>>n;
	vector<ll> temp;
	vector<vector<ll> > adj(n,temp);
	for(ll i=0;i<n;i++)
    {
        cin>>p;
        adj[i].pb(p-1);
        adj[p-1].pb(i);
    }
    cout<<dfsV(adj);
	return 0;
}
