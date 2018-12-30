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

vector<pair<ll,ll>> adj[MAXN];
ll depth[MAXN],par[MAXN];
ll head[MAXN],heavy[MAXN],pos[MAXN],endpos[MAXN],tim=0;
vector<ll> stree[4*MAXN];
ll a[MAXN],V[MAXN];

void build(ll node, ll s, ll e){
    if(s==e){
        stree[node].pb(a[s]);
        return;
    }
    ll mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    merge(all(stree[2*node]),all(stree[2*node+1]),back_inserter(stree[node]));
}

ll query(ll node, ll s, ll e, ll l, ll r, ll left, ll right){
    if(r<s || l>e) return 0;
    if(s>=l && e<=r)
        return upper_bound(all(stree[node]),right)-upper_bound(all(stree[node]),left-1);
    ll mid=(s+e)/2;
    ll p1=query(2*node,s,mid,l,r,left,right),p2=query(2*node+1,mid+1,e,l,r,left,right);
    return p1+p2;
}

ll dfs(ll u){
    ll siz=1,maxsiz=0;
    heavy[u]=-1;
    for(auto v:adj[u]){
        if(v.ff!=par[u]){
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
    a[tim]=V[u];
    pos[u]=tim++;
    if(heavy[u]!=-1)
        hld(heavy[u],h);
    for(auto v:adj[u]){
        if(v.ff!=par[u] && v.ff!=heavy[u])
            hld(v.ff,v.ff);
    }
    endpos[u]=tim-1;
}

ll query_hld(ll u, ll v, ll left, ll right){
    ll ans=0;
    if(V[u]>=left && V[u]<=right) ans--;
    if(V[v]>=left && V[v]<=right) ans--;
    while(head[u]!=head[v]){
        if(depth[head[u]]>depth[head[v]]) swap(u,v);
        ll cur=query(1,0,tim-1,pos[head[v]],pos[v],left,right);
        ans+=cur;
        v=par[head[v]];
    }
    if(depth[u]>depth[v]) swap(u,v);
    ll cur=query(1,0,tim-1,pos[u],pos[v],left,right);
    ans+=cur;
    return ans;
}

ll query_hld1(ll u, ll v, ll left, ll right){
    ll ans=0;
    if(pos[v]>=pos[u] && pos[v]<=endpos[u]){
        ans=query(1,0,tim-1,0,tim-1,left,right);
        for(auto e:adj[u]){
            if(e.ff!=par[u]){
                if(pos[v]>=pos[e.ff] && pos[v]<=endpos[e.ff]){
                    ans-=query(1,0,tim-1,pos[e.ff],endpos[e.ff],left,right);
                    break;
                }
            }
        }
    } else ans=query(1,0,tim-1,pos[u],endpos[u],left,right);
    if(V[u]>=left && V[u]<=right) ans--;
    return ans;
}

int main()
{
	FastIO
	ll n,q,p,i,u,v,l,l1,r1,l2,r2,last=0;
	cin>>n>>q>>p;
	for(i=1;i<=n;i++){
	    cin>>V[i];
	    V[i]%=p;
	}
	for(i=0;i<n-1;i++){
	    cin>>u>>v;
	    adj[u].pb({v,1});
	    adj[v].pb({u,1});
	}
	dfs(1);
	hld(1,1);
	build(1,0,tim-1);
	for(i=0;i<q;i++){
	    cin>>u>>v>>l1>>r1>>l2>>r2;
	    u^=last;v^=last;l1^=last,r1^=last;l2^=last,r2^=last;
	    ll ans1=query_hld(u,v,l1,r1),ans2=query_hld1(u,v,l2,r2);
	    last=ans1*ans2;
	    cout<<last<<"\n";
	}
	return 0;
}
