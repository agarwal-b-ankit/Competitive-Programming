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

ll spf[MAXN];
bool isPrime[MAXN];
vector<ll> prime;

void sieve(ll n){
    ll i;
    for(i=2;i<=n;i++) isPrime[i]=true;
    for(i=2;i<=n;i++){
        if(isPrime[i]){
            spf[i]=i;
            prime.pb(i);
        }
        for(ll p:prime){
            if(p>spf[i] || i*p>n) break;
            spf[i*p]=p;
            isPrime[i*p]=false;
        }
    }
}

int main()
{
	//FastIO
	ll i,n=30;
	sieve(n);
	cout<<"All primes less than 30 are: ";
	for(i=2;i<n;i++)
        if(isPrime[i]) cout<<i<<" ";
	return 0;
}
