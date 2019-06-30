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

vector<pair<ll,ll>> v[MAXN];
ll ans[1<<18],inv2;

ll po(ll n, ll p){
    if(p==0) return 1;
    ll ans=po(n,p/2);
    ans=(ans*ans)%mod;
    if(p%2==1) return (ans*n)%mod;
    else return ans;
}

void fwt(ll n) {
	for (ll d = 1; d < n; d <<= 1) {
		for (ll i = 0, m = d<<1; i < n; i += m) {
			for (ll j = 0; j < d; j++) {
				ll x = ans[i+j], y = ans[i+j+d];
				ans[i+j] = (x+y)%mod, ans[i+j+d] = (x-y)%mod;
			}
		}
	}
}

void ufwt(ll n) {
	for (ll d = 1; d < n; d <<= 1) {
		for (ll i = 0, m = d<<1; i < n; i += m) {
			for (ll j = 0; j < d; j++) {
				ll x = ans[i+j], y = ans[i+j+d];
				ans[i+j] = (((x+y)%mod)*inv2)%mod, ans[i+j+d] = (((x-y)%mod)*inv2)%mod;
			}
		}
	}
}

void solve(ll n) {
	fwt(n);
	for (ll i = 0; i < n; i++)
		ans[i] = (ans[i]*ans[i])%mod;
	ufwt(n);
}

void cal(ll u, ll p, ll xsum){
    ans[xsum]++;
    for(auto e:v[u]){
        if(e.ff!=p)
            cal(e.ff,u,xsum^e.ss);
    }
}

int main()
{
	//FastIO
	inv2=po(2,mod-2);
	ll n,x,y,z,i,res=0;
	cin>>n;
	for(i=0;i<n-1;i++){
	    cin>>x>>y>>z;
	    x--;y--;
	    v[x].pb({y,z});
	    v[y].pb({x,z});
	}
	cal(0,-1,0);
	solve(1<<18);
	for(i=0;i<1<<18;i++){
	    res+=(ans[i]*ans[i])%mod;
	    res%=mod;
        for(ll j=0;j<18;j++){
            ll k=i^(1<<j);
            res+=(ans[i]*ans[k])%mod;
            res%=mod;
        }
    }
    cout<<res;
	return 0;
}