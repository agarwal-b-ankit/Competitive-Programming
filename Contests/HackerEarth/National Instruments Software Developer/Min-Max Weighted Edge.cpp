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

vector<ll> adj[MAXN];
ll deg[MAXN];
bool vis[MAXN];
map<ll,ll> m;

ll centre(ll n){
    ll ans;
    queue<ll> q;
    for(ll i=1;i<=n;i++)
        if(deg[i]==1) q.push(i);
    while(!q.empty()){
        ans=q.front();q.pop();
        for(auto e:adj[ans]){
            deg[e]--;
            if(deg[e]==1) q.push(e);
        }
    }
    return ans;
}

void dfs(ll src, ll depth){
    vis[src]=true;
    if(adj[src].size()==1) m[depth]++;
    for(auto e:adj[src])
        if(!vis[e])
            dfs(e,depth+1);
}

void init(ll n){
    m.clear();
    for(ll i=0;i<=n;i++){
        adj[i].clear();
        deg[i]=0;
        vis[i]=false;
    }
}

int main()
{
	//FastIO
	ll t,n,s,u,v,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		init(n);
		for(i=0;i<n-1;i++){
		    cin>>u>>v;
		    adj[u].pb(v);
		    adj[v].pb(u);
		    deg[u]++;
		    deg[v]++;
		}
		if(n<=2) cout<<s<<"\n";
		else{
    		ll cent=centre(n);
    		dfs(cent,0);
    	    if(m.size()==1 || (m.size()==2 && m.rbegin()->ss==1))
    		    cout<<(s+n-2)/(n-1)<<"\n";
    		else cout<<"0\n";
		}
	}
	return 0;
}
