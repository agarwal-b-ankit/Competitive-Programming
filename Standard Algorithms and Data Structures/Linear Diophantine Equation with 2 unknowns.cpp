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

void findSolutions(ll a, ll b, ll c){
    // degenerate case
    if(a==0 && b==0){
        if(c==0) cout<<"Infinite Solutions. x and y can take any integer values independently\n";
        else cout<<"No Solution\n";
        return;
    }
    ll d = gcd(a,b);
    if(c%d==0){
        ll x0,y0;
        tie(x0,y0)=findAnySolution(a,b,c);
        cout<<"General Solution - \n";
        cout<<"x = "<<x0<<" + "<<(b/d)<<"k for any integer k\n";
        cout<<"y = "<<y0<<" - "<<(a/d)<<"k for any integer k\n";
    } else cout<<"No Solution";
}

int main()
{
	//FastIO
	ll a,b,c;
	cin>>a>>b>>c;
	findSolutions(a,b,c);
	return 0;
}
