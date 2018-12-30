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
ll head[MAXN],heavy[MAXN],pos[MAXN],tim=0;
ll a[MAXN],tree[2*MAXN];
map<pair<ll,ll>,ll> deep;

void update(ll node, ll s, ll e, ll ind, ll val){
    if(s==e){
        tree[node]+=val;
        return;
    }
    ll mid=(s+e)/2;
    if(ind>=s && ind<=mid){
        update(2*node,s,mid,ind,val);
    } else{
        update(2*node+1,mid+1,e,ind,val);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(ll node, ll s, ll e, ll l, ll r){
    if(r<s || l>e) return 0;
    if(s>=l && e<=r) return tree[node];
    ll mid=(s+e)/2;
    ll p1=query(2*node,s,mid,l,r),p2=query(2*node+1,mid+1,e,l,r);
    return p1+p2;
}

ll dfs(ll u){
    ll siz=1,maxsiz=0;
    for(auto v:adj[u]){
        if(v.ff!=par[u]){
            deep[{u,v.ff}]=v.ff;
            deep[{v.ff,u}]=v.ff;
            par[v.ff]=u;
            depth[v.ff]=depth[u]+1;
            ll subsiz=dfs(v.ff);
            siz+=subsiz;
            if(subsiz>maxsiz){
                maxsiz=subsiz;
                heavy[u]=v.ff;
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
    for(auto v:adj[u]){
        if(v.ff!=par[u] && v.ff!=heavy[u])
            hld(v.ff,v.ff);
    }
}

ll query_hld(ll u, ll v){
    ll ans=0;
    while(head[u]!=head[v]){
        if(depth[head[u]]>depth[head[v]]) swap(u,v);
        ll cur=query(1,0,tim-1,pos[head[v]],pos[v]);
        ans+=cur;
        v=par[head[v]];
    }
    if(depth[u]>depth[v]) swap(u,v);
    ll cur=query(1,0,tim-1,pos[u]+1,pos[v]);
    ans+=cur;
    return ans;
}

int main()
{
	//FastIO
	ll n,q,i,u,v,l;
	cin>>n>>q;
	vector<pair<ll,pair<ll,pair<ll,ll>>>> qry;
	vector<pair<ll,pair<ll,ll>>> edges;
	for(i=0;i<n-1;i++){
	    cin>>u>>v>>l;
	    adj[u].pb({v,l});
	    adj[v].pb({u,l});
	    edges.pb({l,{u,v}});
	}
	for(i=0;i<q;i++){
	    cin>>u>>v>>l;
	    qry.pb({l,{i,{u,v}}});
	}
	vector<ll> ans(q+1,0);
	sort(all(qry));
	sort(all(edges));
	memset(heavy,-1,sizeof(heavy));
	dfs(1);
	hld(1,1);
	i=0;
	for(auto qr:qry){
	    while(i<edges.size() && edges[i].ff<=qr.ff){
	        ll vpos=pos[deep[{edges[i].ss.ff,edges[i].ss.ss}]];
	        update(1,0,tim-1,vpos,1);
	        i++;
	    }
	    ll a=qr.ss.ss.ff,b=qr.ss.ss.ss;
	    ans[qr.ss.ff]=query_hld(a,b);
	}
	for(i=0;i<q;i++) cout<<ans[i]<<"\n";
	return 0;
}
