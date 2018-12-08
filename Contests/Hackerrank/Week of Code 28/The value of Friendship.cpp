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

ll fun(ll n)
{
    ll s=0;
    for(ll i=1;i<=n;i++)
        s+=i*(i-1);
    return s;
}

ll dfs(vector<vector<ll> > &adj, vector<bool> &vis, ll st)
{
    vis[st]=true;
    ll siz=1;
    for(ll i:adj[st])
        if(!vis[i])
            siz+=dfs(adj,vis,i);
    return siz;
}

ll dfsV(vector<vector<ll> > &adj, ll n, ll m)
{
    vector<bool> vis(adj.size(),false);
    ll ans=0;
    vector<ll> vec;
    for(ll i=0;i<adj.size();i++)
    {
        if(!vis[i])
        {
            ll siz=dfs(adj,vis,i);
            vec.pb(siz-1);
        }
    }
    sort(vec.rbegin(),vec.rend());
    vector<ll> pre(vec.size(),0);
    pre[0]=vec[0];
    for(ll i=0;i<vec.size();i++)
    {
        if(i>0)
            pre[i]+=pre[i-1]+vec[i];
        ans+=vec[i]*(vec[i]+1)*(m-pre[i]+1)+fun(vec[i]);
    }
    return ans;
}

int main()
{
	ll q;
	cin>>q;
	while(q--)
    {
        ll n,m,m1;
        cin>>n>>m;
        m1=m;
        vector<ll> temp;
        vector<vector<ll> > adj(n,temp);
        while(m--)
        {
            ll a,b;
            cin>>a>>b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        ll ans=dfsV(adj,n,m1);
        cout<<ans<<endl;
    }
	return 0;
}
