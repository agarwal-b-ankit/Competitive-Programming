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

int main()
{
	ll n,k,i,top=1e10;
	cin>>n>>k;
	vector<pair<ll,ll>> v(n);
	vector<ll> pre(n),ans(n);
	for(i=0;i<n;i++){
        cin>>v[i].ff;
        v[i].ss=i;
	}
	sort(all(v));
	pre[0]=v[0].ff;
	for(i=1;i<n;i++) pre[i]=pre[i-1]+v[i].ff;
	for(i=0;i<n;i++){
        ll lb=upper_bound(all(v),mp(v[i].ff-k,top))-v.begin();
        ll ub=(upper_bound(all(v),mp(v[i].ff+k-1,top))-v.begin())-1;
        if(lb==0){
            ans[v[i].ss]=pre[n-1]-pre[ub]-(n-1-ub)*v[i].ff;
        } else {
            ans[v[i].ss]=pre[n-1]-pre[ub]-(n-1-ub)*v[i].ff+v[i].ff*(lb)-pre[lb-1];
        }
	}
	for(i=0;i<n;i++) cout<<ans[i]<<" ";
	return 0;
}
