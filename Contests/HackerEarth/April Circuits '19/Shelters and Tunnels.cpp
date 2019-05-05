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
	//FastIO
	ll n,x,y,i,deg=1,cnt=0;
	cin>>n;
	vector<vector<ll>> v(n+1);
	for(i=1;i<n;i++){
	    cin>>x>>y;
	    v[x].pb(y);
	    v[y].pb(x);
	    deg=max(deg,(ll)v[x].size());
	    deg=max(deg,(ll)v[y].size());
	}
	for(i=1;i<=n;i++)
	    if(v[i].size()==deg)
	        cnt++;
	cout<<cnt<<"\n";
	for(i=1;i<=n;i++)
	    if(v[i].size()==deg)
	        cout<<i<<" ";
	return 0;
}