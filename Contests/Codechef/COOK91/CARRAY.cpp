#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define present(m,v) (m.find(v)!=m.end())
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

ll fun(vector<ll> &v, ll i, ll k, ll b) {
    if(i==v.size())
        return 0;
    if(v[i]*k+b>v[i]){
        ll j=lower_bound(v.begin(),v.end(),v[i]*k+b)-v.begin();
        return 1+fun(v,j,k,b);
    }
    else return v.size()-i;
}


int main()
{
	ll t,n,k,b,i;
	cin>>t;
	while(t--){
        scanf("%lld%lld%lld",&n,&k,&b);
        vector<ll> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        sort(all(v));
        printf("%lld\n",fun(v,0,k,b));
	}
	return 0;
}
