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
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

ll a[510];

int main()
{
	FastIO
	ll n,q,i,j,type,l,r,x;
	cin>>n>>q;
	for(i=1;i<=n;i++)
        cin>>a[i];
    vector<pair<pair<ll,ll> ,pair<ll,ll> > > v;
	for(i=0;i<q;i++){
		cin>>type>>l>>r>>x;
		if(type==1 && x<0)
            v.pb(mp(mp(0,x),mp(l,r)));
        else if(type==1)
            v.pb(mp(mp(2,x),mp(l,r)));
        else v.pb(mp(mp(1,x),mp(l,r)));
	}
	sort(all(v));
	for(i=0;i<v.size();i++){
	    for(j=v[i].ss.ff;j<=v[i].ss.ss;j++){
            if(v[i].ff.ff==1) a[j]=v[i].ff.ss;
            else a[j]+=v[i].ff.ss;
	    }
	}
	for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
	}
	return 0;
}
