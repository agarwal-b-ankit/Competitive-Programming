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
 
ll fact[2010];
 
ll po(ll n, ll p, ll m){
    if(p==0) return 1;
    ll ans=po(n,p/2,m);
    ans=(ans*ans)%m;
    if(p%2==1) return (ans*n)%m;
    else return ans;
}
 
ll modInversePrime(ll a, ll m){
    return po(a,m-2,m);
}
 
int main()
{
	//FastIO
	ll t,n,i,ans=0;
	cin>>n;
	fact[0]=1;
	for(i=1;i<2010;i++)
	    fact[i]=(fact[i-1]*i)%mod;
	for(i=1;i<=(n+1)/2;i++){
	    ll temp=fact[n-i+1];
	    ll base=(fact[i]*fact[n-2*i+1])%mod;
	    temp=(temp*modInversePrime(base,mod))%mod;
	    ans+=(temp*fact[i])%mod;
	    ans%=mod;
	}
	cout<<ans;
	return 0;
}