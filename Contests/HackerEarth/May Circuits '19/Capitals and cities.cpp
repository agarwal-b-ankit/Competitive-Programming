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
 
ll cal(ll sum, ll k){
    if(sum>=k) return sum-k;
    else return (k-sum)%2;
}
 
int main()
{
	//FastIO
	ll n,k,i,ans=INF,occ=INF;
	cin>>n>>k;
	if(n==1){
	    cout<<"1 0";
	    return 0;
	}
	vector<pair<ll,ll>> v(n);
	vector<ll> pre(n+1,0),post(n+1,0);
	for(i=0;i<n;i++){
	    cin>>v[i].first;
	    v[i].second=i+1;
	}
	sort(all(v));
	for(i=1;i<n;i++)
	    pre[i]=pre[i-1]+i*(v[i].ff-v[i-1].ff);
	for(i=n-1;i>=0;i--){
	    if(i<n-1)
	        post[i]=post[i+1]+(n-i-1)*(v[i+1].ff-v[i].ff);
	    ll temp=cal(pre[i]+post[i],k);
	    if(temp<ans){
	        ans=temp;
	        occ=v[i].ss;
	    } else if(temp==ans)
	        occ=min(occ,v[i].ss);
	}
	cout<<occ<<" "<<ans;
	return 0;
}