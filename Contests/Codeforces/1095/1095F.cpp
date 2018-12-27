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

ll par[MAXN],ran[MAXN];

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

int main()
{
	//FastIO
	ll n,m,i,x,y,w,cnt=0,ans=0;
	cin>>n>>m;
	vector<pair<ll,ll>> a(n+1);
	vector<pair<ll,pair<ll,ll>>> v;
	for(i=1;i<=n;i++){
        cin>>a[i].ff;
        a[i].ss=i;
	}
	sort(all(a));
	for(i=2;i<=n;i++)
        v.pb({a[1].ff+a[i].ff,{a[1].ss,a[i].ss}});
	for(i=0;i<m;i++){
        cin>>x>>y>>w;
        v.pb({w,{x,y}});
	}
	sort(all(v));
	init(n+1);
	i=0;
	while(cnt<n-1){
        if(uni(v[i].ss.ff,v[i].ss.ss)){
            cnt++;
            ans+=v[i].ff;
        }
        i++;
	}
	cout<<ans;
	return 0;
}
