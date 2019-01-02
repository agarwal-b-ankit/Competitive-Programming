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

ll dp[MAXN][4];

int main()
{
	//FastIO
	ll t,n,i,j;
	cin>>n;
	string s;
	string hard="hard";
	cin>>s;
	ll a[n];
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) for(j=0;j<4;j++) dp[i][j]=INF;
	if(s[0]==hard[0]) dp[0][1]=0,dp[0][0]=a[0];
	else dp[0][0]=0;
	for(i=1;i<n;i++){
        for(j=0;j<4;j++){
            if(s[i]==hard[j]) dp[i][j]=(dp[i-1][j]!=INF)?dp[i-1][j]+a[i]:dp[i][j];
            else if(j>0 && s[i]==hard[j-1]) dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
	}
	cout<<min(min(dp[n-1][0],dp[n-1][1]),min(dp[n-1][2],dp[n-1][3]));
	return 0;
}
