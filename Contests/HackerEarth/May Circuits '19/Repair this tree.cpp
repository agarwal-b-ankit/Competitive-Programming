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
const ll MAXN=200001;
 
vector<pair<int,int>> adj[MAXN];
int depth[MAXN],par[MAXN];
int head[MAXN],heavy[MAXN],pos[MAXN],tim=0;
unordered_set<ll> stree[3*MAXN];
int a[MAXN];
int mark;
 
map<ll,vector<pair<ll,pair<ll,ll>>>> m;
ll spf[1000001];
 
void sieve(){
    ll i,j,n=1000001;
    for(i=1;i<n;i++) spf[i]=i;
    for(i=4;i<n;i+=2) spf[i]=2;
    for(i=3;i*i<n;i++){
        if(spf[i]==i){
            for(j=i*i;j<n;j+=i){
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}
 
vector<ll> getPrimeFactors(ll x){
    vector<ll> pf;
    while(x>1){
        pf.pb(spf[x]);
        ll temp=spf[x];
        while(x%temp==0)
            x/=temp;
    }
    return pf;
}
 
void build(ll node, ll s, ll e){
    if(s==e){
        stree[node].insert(a[s]);
        return;
    }
    ll mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    merge(all(stree[2*node]),all(stree[2*node+1]),inserter(stree[node],stree[node].end()));
}
 
void query(ll node, ll s, ll e, ll l, ll r, ll val){
    if(r<s || l>e) return ;
    if(s>=l && e<=r){
        if(present(stree[node],val))
            mark++;
        if(present(stree[node],par[val]))
            mark++;
        return ;
    }
    ll mid=(s+e)/2;
    query(2*node,s,mid,l,r,val);
    query(2*node+1,mid+1,e,l,r,val);
}
 
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
    a[tim]=u;
    pos[u]=tim++;
    if(heavy[u]!=-1)
        hld(heavy[u],h);
    for(auto p:adj[u]){
        ll v=p.ff;
        if(v!=par[u] && v!=heavy[u])
            hld(v,v);
    }
}
 
bool query_hld(ll u, ll v, ll val){
    mark=0;
    while(head[u]!=head[v]){
        if(depth[head[u]]>depth[head[v]]) swap(u,v);
        query(1,0,tim-1,pos[head[v]],pos[v],val);
        v=par[head[v]];
    }
    if(depth[u]>depth[v]) swap(u,v);
    query(1,0,tim-1,pos[u],pos[v],val);
    if(mark==2) return true;
    else return false;
}
 
int main()
{
	FastIO
	ll n,q,i,u,ans=0,type,x,y,w;
	cin>>n>>q;
	for(i=2;i<=n;i++){
	    cin>>u;
	    adj[i].pb({u,1});
	    adj[u].pb({i,1});
	}
	sieve();
	dfs(1);
	hld(1,1);
	build(1,0,tim-1);
	for(i=0;i<q;i++){
	    cin>>type>>x>>y;
	    if(type==1){
	        cin>>w;
	        x=(x+ans-1)%n+1;
	        y=(y+ans-1)%n+1;
	        if(x==y) continue;
	        vector<ll> pf=getPrimeFactors(w);
	        for(auto f:pf)
	            m[f].pb({w,{x,y}});
	    } else{
	        x=(x+ans-1)%(n-1)+2;
	        ans=0;
	        for(auto e:m[y]){
	            if(query_hld(e.ss.ff,e.ss.ss,x))
	                ans+=e.ff;
	        }
	        cout<<ans<<"\n";
	    }
	}
	return 0;
}