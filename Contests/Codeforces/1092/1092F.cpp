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
const ll MAXN=200010;

ll a[MAXN],ans=0;
pair<ll,ll> b[MAXN];
bool vis[MAXN];
vector<ll> adj[MAXN];

pair<ll,ll> dfs(ll u){
    vis[u]=true;
    ll tsum=0,nsum=a[u];
    for(auto v:adj[u]){
        if(vis[v]) continue;
        auto val=dfs(v);
        tsum+=(val.ff+val.ss);
        nsum+=val.ss;
    }
    return b[u]={tsum,nsum};

}

void dfs1(ll u, ll par, ll tsum, ll nsum){
    vis[u]=true;
    for(auto v:adj[u]){
        if(v==par) continue;
        tsum+=b[v].ff;
        nsum+=b[v].ss;
    }
    ans=max(ans,tsum+nsum);
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs1(v, u, tsum-b[v].ff+nsum-b[v].ss, nsum-b[v].ss+a[u]);
        }
    }
}

int main()
{
	//FastIO
	ll n,i,u,v;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
	}
	dfs(1);
	memset(vis,false,sizeof(vis));
	dfs1(1,0,0,0);
	cout<<ans;
	return 0;
}
