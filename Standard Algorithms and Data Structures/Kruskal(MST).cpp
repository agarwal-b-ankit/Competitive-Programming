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
vector<pair<ll,pair<ll,ll>>> edges;

void init(ll n){
    for(ll i=0;i<n;i++){
        par[i]=i;
        ran[i]=1;
    }
}

ll fin(ll x){
    if(par[x]!=x)
        par[x]=fin(par[x]);
    return par[x];
}

bool uni(ll x, ll y){
    ll px=fin(x),py=fin(y);
    if(px==py) return false;
    if(ran[px]<ran[py]){
        par[px]=py;
        ran[py]+=ran[px];
    }
    else{
        par[py]=px;
        ran[px]+=ran[py];
    }
    return true;
}

ll kruskal(ll n){
    init(n);
    sort(all(edges));
    ll cost=0,cnt=0;
    for(auto edge:edges){
        ll u=edge.ss.ff,v=edge.ss.ss,w=edge.ff;
        if(uni(u,v)){
            cnt++;
            cost+=w;
            cout<<"edge: "<<u<<" "<<v<<endl;
        }
        if(cnt==n-1) break;
    }
    return cost;
}

void addEdge(ll u, ll v, ll w){
    edges.pb({w,{u,v}});
}

int main()
{
	//FastIO
	ll t,n,i;
	n=9;
	addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
	cout<<"Weight of MST is "<<kruskal(n);
	return 0;
}
