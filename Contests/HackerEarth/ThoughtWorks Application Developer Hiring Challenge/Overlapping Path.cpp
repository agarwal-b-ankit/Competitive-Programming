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
const ll MAXN=500010;

vector<ll> adj[MAXN];
vector<ll> unode,vnode;
map<ll,ll> pnode;
ll vis[MAXN];

void add(ll u, vector<ll> &ve){
    vis[u]=1;
    if(present(pnode,u)) return;
    ve.pb(u);
    for(ll e:adj[u])
        if(!vis[e])
            add(e,ve);
}

ll dfs(ll u, ll v){
    if(u==v){
        pnode[u]++;
        return 1;
    }
    vis[u]=1;
    ll ans=0;
    for(ll e:adj[u])
        if(!vis[e])
            ans+=dfs(e,v);
    if(ans==1) pnode[u]++;
    return ans;
}

int main()
{
	FastIO
	ll t,n,i,a,b,u,v;
	cin>>t;
	while(t--)
	{
	    pnode.clear();
	    unode.clear();
	    vnode.clear();
		cin>>n;
		for(i=1;i<=n;i++) adj[i].clear();
		for(i=0;i<n-1;i++){
		    cin>>a>>b;
		    adj[a].pb(b);
		    adj[b].pb(a);
		}
		cin>>u>>v;
		memset(vis,0,sizeof(vis));
		dfs(u,v);
		pnode.erase(u);
		memset(vis,0,sizeof(vis));
		add(u,unode);
		pnode[u]++;
		pnode.erase(v);
		memset(vis,0,sizeof(vis));
		add(v,vnode);
		ll ans=0;
		for(ll un:unode)
		    for(ll vn:vnode)
		        ans=max(ans,__gcd(un,vn));
		cout<<ans<<"\n";
	}
	return 0;
}
