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

ll par[MAXN],ran[MAXN];

void init(ll n){
    for(ll i=0;i<n;i++){
        par[i]=i;
    }
}

ll fin(ll x){
    if(par[x]!=x)
        par[x]=fin(par[x]);
    return par[x];
}

ll uni(ll x, ll y){
    ll px=fin(x),py=fin(y);
    if(px==py) return ran[px];
    if(ran[px]<ran[py]){
        par[px]=py;
        return ran[py]+=ran[px];
    }
    else{
        par[py]=px;
        return ran[px]+=ran[py];
    }
}

ll kruskal(vector<pair<ll,pair<ll,ll>>> &edges, ll n, ll k){
    init(n+10);
    sort(all(edges));
    for(auto edge:edges){
        ll u=edge.ss.ff,v=edge.ss.ss,w=edge.ff;
        if(uni(u,v)==k){
            return w;
        }
    }
    return 0;
}

int main()
{
	//FastIO
	ll n,m,k,i,val,u,v,w;
	cin>>n>>m>>k;
	vector<pair<ll,pair<ll,ll>>> edges;
	for(i=0;i<k;i++){
        cin>>val;
        ran[val]=1;
	}
	for(i=0;i<m;i++){
        cin>>u>>v>>w;
        edges.pb({w,{u,v}});
	}
	ll ans=kruskal(edges,n,k);
	for(i=0;i<k;i++) cout<<ans<<" ";
	return 0;
}
