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

bool vis[MAXN];
vector<ll> adj[MAXN];
map<ll,ll> deg;
vector<pair<ll,ll>> dicent;

void dfs(ll u, queue<ll> &q){
    vis[u]=true;
    if(deg[u]<=1) q.push(u);
    for(ll v:adj[u])
        if(!vis[v])
            dfs(v,q);
}

void solve(ll src){
    queue<ll> q;
    dfs(src,q);
    ll dia=0,cent,siz;
    while(!q.empty()){
        siz=q.size();
        for(ll i=0;i<siz;i++){
            cent=q.front();
            q.pop();
            for(ll v: adj[cent]){
                deg[v]--;
                if(deg[v]==1) q.push(v);
            }
        }
        if(!q.empty())
            dia+=2;
        else if(siz==2) dia++;
    }
    dicent.pb({dia,cent});
}

ll getDia(ll src){
    queue<ll> q;
    memset(vis,false,sizeof(vis));
    q.push(src);
    ll u,v1,dia=0;
    while(!q.empty()){
        u=q.front();q.pop();
        vis[u]=true;
        for(ll v:adj[u])
            if(!vis[v]) q.push(v);
    }
    memset(vis,false,sizeof(vis));
    q.push(u);
    while(!q.empty()){
        ll siz=q.size();
        while(siz--){
            u=q.front();q.pop();
            vis[u]=true;
            for(ll v:adj[u])
                if(!vis[v]) q.push(v);
        }
        if(!q.empty()) dia++;
    }
    return dia;
}

int main()
{
	//FastIO
	ll n,m,i,u,v;
	cin>>n>>m;
	for(i=0;i<m;i++){
	    cin>>u>>v;
	    adj[u].pb(v);
	    adj[v].pb(u);
	    deg[u]++;
	    deg[v]++;
	}
	for(i=1;i<=n;i++){
	    if(!vis[i])
	        solve(i);
	}
	sort(all(dicent),greater<pair<ll,ll>>());
	for(i=1;i<dicent.size();i++){
        adj[dicent[0].ss].pb(dicent[i].ss);
        adj[dicent[i].ss].pb(dicent[0].ss);
	}
	cout<<getDia(1)<<"\n";
	for(i=1;i<dicent.size();i++)
        cout<<dicent[0].ss<<" "<<dicent[i].ss<<"\n";
	return 0;
}
