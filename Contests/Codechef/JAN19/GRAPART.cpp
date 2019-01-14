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
ll cnt[MAXN];

void dfs(ll u, ll par, ll flag, vector<ll>& ans){
    ans.pb(u);
    cnt[flag]++;
    for(auto e:adj[u])
        if(e!=par)
            dfs(e,u,1-flag,ans);
}

int main()
{
	//FastIO
	ll t,n,i,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<=n;i++) adj[i].clear();
		for(i=0;i<n-1;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
		}
		vector<ll> ans;
		dfs(1,-1,0,ans);
		if(cnt[0]==cnt[1]) cout<<"1\n";
		else cout<<"2\n";
		for(i=0;i<ans.size();i+=2) cout<<ans[i]<<" ";
		cout<<"\n";
		for(i=1;i<ans.size();i+=2) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
