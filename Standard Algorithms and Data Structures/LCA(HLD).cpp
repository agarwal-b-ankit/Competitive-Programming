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

vector<pair<ll,ll>> adj[MAXN];
ll depth[MAXN],par[MAXN];
ll head[MAXN],heavy[MAXN],pos[MAXN],endpos[MAXN],tim=0;
ll stree[4*MAXN];
//map<pair<ll,ll>,ll> deep;

ll dfs(ll u){
    ll siz=1,maxsiz=0;
    heavy[u]=-1;
    for(auto p:adj[u]){
        ll v=p.ff;
        if(v!=par[u]){
            par[v]=u;
            depth[v]=depth[u]+1;
            ll subsiz=dfs(v);
            siz+=subsiz;
            if(subsiz>maxsiz){
                maxsiz=subsiz;
                heavy[u]=v;
            }
        }
    }
    return siz;
}

void hld(ll u, ll h){
    head[u]=h;
    pos[u]=tim++;
    if(heavy[u]!=-1)
        hld(heavy[u],h);
    for(auto p:adj[u]){
        ll v=p.ff,w=p.ss;
        if(v!=par[u] && v!=heavy[u])
            hld(v,v);
    }
    endpos[u]=tim-1;
}

ll query_hld(ll u, ll v){
    while(head[u]!=head[v]){
        if(depth[head[u]]>depth[head[v]]) swap(u,v);
        v=par[head[v]];
    }
    if(depth[u]>depth[v]) swap(u,v);
    return u;
}

ll getLCA(ll u, ll v){
    return query_hld(u,v);
}

ll addEdge(ll u, ll v){
    adj[u].pb({v,1});
    adj[v].pb({u,1});
}

int main()
{
	//FastIO
	ll n,m,i,u,v;
	addEdge(1,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);
	addEdge(5,8);
	addEdge(5,9);
	addEdge(3,6);
	addEdge(3,7);
	dfs(1);
	hld(1,1);
	cout<<getLCA(8,2)<<"\n";
	cout<<getLCA(5,6)<<"\n";
	cout<<getLCA(1,1)<<"\n";
	cout<<getLCA(9,9)<<"\n";
	cout<<getLCA(4,2)<<"\n";
	cout<<getLCA(4,8)<<"\n";
	cout<<getLCA(8,9)<<"\n";
	cout<<getLCA(9,6)<<"\n";
	cout<<getLCA(4,6)<<"\n";
	cout<<getLCA(4,7)<<"\n";
	cout<<getLCA(4,3)<<"\n";
	cout<<getLCA(4,1)<<"\n";
	return 0;
}
