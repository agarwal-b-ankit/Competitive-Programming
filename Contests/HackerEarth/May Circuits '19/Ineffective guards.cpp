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
 
int main()
{
	FastIO
	ll n,m,i,j;
	cin>>n>>m;
	vector<pair<ll,ll>> grd(n),jew(m);
	set<ll> s;
	for(i=0;i<n;i++)
	    cin>>grd[i].ff>>grd[i].ss;
	for(i=0;i<m;i++)
	    cin>>jew[i].ff>>jew[i].ss;
	sort(all(grd));
	sort(all(jew));
	for(i=0;i<m;i++){
	    ll cnt=-1;
	    ll pos=upper_bound(all(grd),make_pair(jew[i].ff-1,INF))-grd.begin();
	    for(j=pos-1;j>=0;j--){
	        if(abs(grd[j].ss-jew[i].ss)<=jew[i].ff-grd[j].ff){
	            if(cnt!=-1){
	                cnt=-1;
	                break;
	            } else cnt=j;
	        }
	    }
	    if(cnt!=-1)
	        s.insert(cnt);
	}
	cout<<n-s.size();
	return 0;
}