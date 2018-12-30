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

ll a[MAXN],dp[MAXN][256],ans;

ll getValue(ll mask, ll l, ll r){
    ll val=(dp[r][mask]-dp[l-1][mask]+mod)%mod;
    return (((val*val)%mod)*val)%mod;
}

int main()
{
	FastIO
	ll n,m,l,r,x,i,j;
	cin>>n;
	for(i=1;i<=n;i++){
	    cin>>a[i];
	    for(j=0;j<256;j++)
	        if((a[i]&j)==j) dp[i][j]=(dp[i-1][j]+1)%mod;
	        else dp[i][j]=dp[i-1][j];
	}
	cin>>m;
	while(m--){
	    cin>>l>>r>>x;
	    ans=0;
	    for(i=0;i<256;i++){
	        if((x&i)==x){
	            if((__builtin_popcount(i)-__builtin_popcount(x))%2==0)
	               ans=(ans+getValue(i,l,r))%mod;
	           else ans=(ans+mod-getValue(i,l,r))%mod;
	        }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
