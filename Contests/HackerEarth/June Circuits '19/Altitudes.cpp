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
 
ll fact[MAXN];
 
ll po(ll n, ll p){
    if(p==0) return 1;
    ll ans=po(n,p/2);
    ans=(ans*ans)%mod;
    if(p%2==1) return (ans*n)%mod;
    else return ans;
}
 
ll ncr(ll n, ll r){
    if(r==0 || r== n) return 1;
    return (fact[n]*((po(fact[r],mod-2)*po(fact[n-r],mod-2))%mod))%mod;
}
 
void precompute(){
    fact[0]=1;
    for(ll i=1;i<MAXN;i++)
        fact[i]=(fact[i-1]*i)%mod;
}
 
ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
// returns any solution of the equation ax + by = 1 when gcd(a,b) = 1
tuple<ll,ll> extended_gcd(ll a, ll b){
	if (a == 0) return make_tuple(0, 1);
	ll x, y;
	tie(x, y) = extended_gcd(b % a, a);
	return make_tuple((y - (b/a) * x), x);
}
 
// returns any solution of the equation ax + by = c
// solution exists only if gcd(a,b) divides c
tuple<ll,ll> findAnySolution(ll a, ll b, ll c){
    ll x0,y0,d=gcd(a,b);
    tie(x0,y0)=extended_gcd(a/d, b/d);
    x0 = (c / d) * x0;
    y0 = (c / d) * y0;
    return make_tuple(x0,y0);
}
 
ll findSolutions(ll a, ll b, ll c, ll n){
    // degenerate case
    if(a==0 && b==0 && c==0) return po(3,n);
    else if(a==0 && b==0) return 0;
    ll d = gcd(a,b);
    if(c%d==0){
        ll x0,y0;
        tie(x0,y0)=findAnySolution(a,b,c);
        if(a==0){
            if(y0<0 || y0>n) return 0;
            return (ncr(n,y0)*po(2,n-y0))%mod;
        } else if(b==0){
            if(x0<0 || x0>n) return 0;
            return (ncr(n,x0)*po(2,n-x0))%mod;
        } else {
            ll k1,k2,ans=0;
            ll ka1=(-x0*d)/b,ka2=((n-x0)*d)/b;
    		ll kb1=(y0*d)/a,kb2=((y0-n)*d)/a;
    		if(ka1>ka2) swap(ka1,ka2);
    		if(kb1>kb2) swap(kb1,kb2);
    		k1=max(ka1,kb1);
    		k2=min(ka2,kb2);
    		for(ll i=k1;i<=k2;i++){
    		    ll x=x0+(i*b)/d,y=y0-(i*a)/d;
    		    ll z=n-x-y;
    		    if(x<0 || x>n || y<0 || y>n || z<0 || z>n) continue;
    		    ans+=(ncr(n,x)*ncr(n-x,y))%mod;
    		    ans%=mod;
		    }
		    return ans;
        }
    } else return 0;
}
 
// solve for scenario when b=c and a!=b
ll solve2(ll n, ll a, ll b, ll H1, ll H2){
    if((H2-H1-b*n)%(a-b)==0){
        ll x=(H2-H1-b*n)/(a-b);
        if(x>=0 && x<=n) return ncr(n,x);
        else return 0;
    } else return 0;
}
 
int main()
{
	//FastIO
	precompute();
	ll n,A,B,C,H1,H2,ans=0;
	cin>>n>>H1>>H2>>A>>B>>C;
	if(A==B && B==C){
	    if(H2-H1==A*n) ans=1;
	    else ans=0;
	} else if(A==B) ans=solve2(n,C,A,H1,H2);
	else if(B==C) ans=solve2(n,A,B,H1,H2);
	else if(A==C) ans=solve2(n,B,A,H1,H2);
	else ans=findSolutions(A-C,B-C,H2-H1-C*n,n);
	cout<<ans;
	return 0;
}