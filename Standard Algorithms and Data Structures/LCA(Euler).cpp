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
ll euler[MAXN],level[MAXN],occ[MAXN],tree[MAXN];
ll ind=0;

void build(ll node, ll s, ll e){
    if(s==e){
        tree[node]=s;
        return;
    }
    ll mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    ll p1=tree[2*node],p2=tree[2*node+1];
    tree[node]=(level[p1]<=level[p2])? p1: p2;
}

ll query(ll node, ll s, ll e, ll l, ll r){
    if(r<s || l>e) return -1;
    if(s>=l && e<=r) return tree[node];
    ll mid=(s+e)/2;
    ll p1=query(2*node,s,mid,l,r),p2=query(2*node+1,mid+1,e,l,r);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return (level[p1]<=level[p2])? p1: p2;
}

void dfs(ll u, ll lev){
    vis[u]=true;
    occ[u]=ind;
    euler[ind]=u;
    level[ind++]=lev;
    for(ll v:adj[u]){
        if(!vis[v]){
            dfs(v,lev+1);
            euler[ind]=u;
            level[ind++]=lev;
        }
    }
}

ll getLCA(ll u, ll v){
    ll occu=occ[u],occv=occ[v];
    if(occu>occv) swap(occu,occv);
    ll index=query(1,0,ind-1,occu,occv);
    return euler[index];
}

ll addEdge(ll u, ll v){
    adj[u].pb(v);
    adj[v].pb(u);
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
	dfs(1,0); // prepare euler tour
	build(1,0,ind-1); // build segment tree using level array
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
