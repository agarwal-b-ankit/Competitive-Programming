
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
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

ll find(ll val,vector<ll> &par,vector<ll> &rank)
{
    if(par[val]!=val)
        par[val]=find(par[val],par,rank);
    return par[val];
}

void uni(ll a, ll b, vector<ll> &par,vector<ll> &rank)
{
    if(rank[a]<rank[b])
        par[a]=b;
    else if(rank[a]>rank[b])
        par[b]=a;
    else
    {
        par[a]=b;
        rank[b]++;
    }
}

int main()
{
	ll t,n,m,i,j,k,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<vector<ll> > adj(n),deg(n+1);
		vector<ll> par(n,0),rank(n,0);
		ll maxd=0;
		for(i=0;i<n;i++)
            par[i]=i;
		for(i=0;i<m;i++)
        {
            scanf("%lld%lld",&u,&v);
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }
        for(i=0;i<n;i++)
        {
            maxd=max(maxd,(ll)adj[i].size());
            deg[adj[i].size()].pb(i);
        }
        ll cmp=n;
        vector<ll> ans;
        for(i=n;i>=1;i--)
        {
            for(j=0;j<deg[i].size();j++)
            {
                for(k=0;k<adj[deg[i][j]].size();k++)
                {
                    if(adj[adj[deg[i][j]][k]].size()>=i)
                    {
                        ll a=deg[i][j];
                        ll b=adj[deg[i][j]][k];
                        ll pa=find(a,par,rank);
                        ll pb=find(b,par,rank);
                        if(pa!=pb)
                        {
                            uni(pa,pb,par,rank);
                            cmp--;
                        }
                    }
                }
            }
            ans.pb(cmp-1);
        }
        reverse(all(ans));
        for(i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
	}
	return 0;
}
