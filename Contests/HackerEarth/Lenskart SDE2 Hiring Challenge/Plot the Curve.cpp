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

ll po(ll n, ll p, ll m){
    if(p==0) return 1;
    ll ans=po(n,p/2,m);
    if(p%2==0) return (ans*ans)%m;
    else return (n*(ans*ans)%m)%m;
}

int main()
{
	FastIO
	ll t,n,i,j,a,b,c,d,m;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d>>m>>n;
		vector<ll> v(n);
		ll ans=0;
		for(i=0;i<n;i++) cin>>v[i];
		map<ll,ll> m1,m2;
		for(i=0;i<n;i++){
            ll sum=((a*po(v[i],3,m))%m+(b*po(v[i],2,m))%m+(c*po(v[i],1,m))%m+d+5*m)%m;
            m1[sum]++;
            m2[po(v[i],2,m)]++;
		}
		for(auto e:m1){
            if(present(m2,e.ff))
                ans=(ans+(e.ss*m2[e.ff])%mod)%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
