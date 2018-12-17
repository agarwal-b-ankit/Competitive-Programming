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
#define mod 998244353
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
ll INF=numeric_limits<ll>::max();
const ll MAXN=100010;

ll dp[2010][2010];

int main()
{
	//FastIO
	ll n,m,k,i,j;
	cin>>n>>m>>k;
	for(i=0;i<n;i++) dp[i][0]=m;
	for(i=1;i<n;i++){
        for(j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j]+(m-1)*dp[i-1][j-1];
            dp[i][j]%=mod;
        }
	}
	cout<<dp[n-1][k];
	return 0;
}
