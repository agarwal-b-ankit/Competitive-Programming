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
	ll n,i;
	cin>>n;
	vector<pair<ll,pair<ll,ll>>> v(n);
	vector<ll> par(n+1,0);
	for(i=0;i<n;i++){
	    cin>>v[i].ff;
	    v[i].ss.ss=i+1;
	}
	for(i=0;i<n;i++) cin>>v[i].ss.ff;
	sort(all(v));
	stack<ll> s;
	for(i=0;i<n;i++){
	    if(s.empty()){
	        s.push(i);
	        par[v[i].ss.ss]=0;
	    } else{
	        while(v[s.top()].ss.ff<v[i].ss.ff)
	            s.pop();
	        par[v[i].ss.ss]=v[s.top()].ss.ss;
	        s.push(i);
	    }
	}
	for(i=1;i<=n;i++)
	    cout<<par[i]<<" ";
	
	return 0;
}