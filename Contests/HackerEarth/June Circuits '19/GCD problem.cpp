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
 
vector<ll> f(MAXN);
 
ll po(ll n, ll p){
    if(p==0) return 1;
    ll ans=po(n,p/2);
    ans=(ans*ans)%mod;
    if(p%2==1) return (ans*n)%mod;
    else return ans;
}
 
ll nc4(ll n){
    if(n<4) return 0;
    ll inv=po(24,mod-2);
    ll num=(((n*(n-1))%mod)*(((n-2)*(n-3))%mod))%mod;
    return (num*inv)%mod;
}
 
ll solve(ll k, ll n){
    if(n/k<4) return f[k]=0;
    if(f[k]!=-1) return f[k];
    ll ans=nc4(n/k);
    for(ll i=k*2;i<=n;i+=k){
        ans=(ans+mod-solve(i,n))%mod;
    }
    return f[k]=ans;
}
 
int main()
{
	//FastIO
	ll t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		fill(all(f),-1);
		ll ans=0;
		if(n>=4){
		    solve(1,n);
		    for(i=1;i<=n;i++)
		        ans=(ans+(f[i]*po(i,4))%mod)%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}