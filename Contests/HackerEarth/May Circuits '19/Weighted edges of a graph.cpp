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
#define mod 987654319
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
ll INF=numeric_limits<ll>::max();
const ll MAXN=300010;
 
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
 
ll uni1(ll x, ll y, ll w=0) {
    ll px = fin(x), py = fin(y);
        if (ran[px] > ran[py]) {
            par[py] = px;
            ll temp = ran[px] * ran[py];
            ran[px] += ran[py];
            return (temp - 1)%mod;
        }
        else {
            par[px] = py;
            ll temp = ran[px] * ran[py];
            ran[py] += ran[px];
            return (temp - 1)%mod;
        }
}
 
ll uni(ll x, ll y){
    ll px=fin(x),py=fin(y);
    ll ans=ran[px]*ran[py]-1;
    if(ran[px]<ran[py]){
        par[px]=py;
        ran[py]+=ran[px];
    }
    else{
        par[py]=px;
        ran[px]+=ran[py];
    }
    return ans;
}
 
ll po(ll n, ll p){
    if(p==0) return 1;
    ll ans=po(n,p/2);
    ans=(ans*ans)%mod;
    if(p%2==0) return ans;
    else return (ans*n)%mod;
}
 
int main()
{
	FastIO
	init(MAXN);
	ll n,maxw,i,u,v,w,ans=1;
	vector<pair<ll,pair<ll,ll>>> adj;
	cin>>n>>maxw;
	for(i=0;i<n-1;i++){
	    cin>>u>>v>>w;
	    adj.pb({w,{u,v}});
	}
	sort(all(adj));
	for(auto e:adj){
	    if(e.ff<=maxw){
	        ans*=po((maxw+2-e.ff)%mod,uni(e.ss.ff,e.ss.ss));
	        ans%=mod;
	    }
	    else{
	        cout<<0;
	        return 0;
	    }
	}
	cout<<ans;
	return 0;
}