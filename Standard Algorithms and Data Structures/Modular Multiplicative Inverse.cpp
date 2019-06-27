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

// METHOD 1: when gcd(a,m) = 1

tuple<ll,ll> extended_gcd(ll a, ll b){
	if (a == 0) return make_tuple(0, 1);
	ll x, y;
	tie(x, y) = extended_gcd(b % a, a);
	return make_tuple((y - (b/a) * x), x);
}

// works only when gcd(a,m) = 1
ll modInverse(ll a, ll m){
    ll x,y;
    tie(x,y)=extended_gcd(a,m);
    // x is mod inverse, make x positive if it's negative
    return (x%m+m)%m;
}

// METHOD 2: when m is prime

ll po(ll n, ll p, ll m){
    if(p==0) return 1;
    ll ans=po(n,p/2,m);
    ans=(ans*ans)%m;
    if(p%2==1) return (ans*n)%m;
    else return ans;
}

// works only when m is prime
ll modInversePrime(ll a, ll m){
    return po(a,m-2,m);
}

int main()
{
	//FastIO
	ll a,b,c;
	cout<<modInverse(2,15)<<endl;
	cout<<modInverse(3,26)<<endl;
	cout<<modInverse(10,28)<<endl;
	cout<<modInverse(2,3)<<" "<<modInversePrime(2,3)<<endl;
	cout<<modInverse(10,29)<<" "<<modInversePrime(10,29)<<endl;
	return 0;
}
