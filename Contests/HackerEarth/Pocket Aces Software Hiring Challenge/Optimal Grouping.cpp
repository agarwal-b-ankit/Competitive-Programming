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

ll dp[510][510],small[510][510],a[510];

int main()
{
	//FastIO
	ll n,k,i,j,i1,num;
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=n;i>0;i--){
	    num=0;
	    for(j=i-1;j>0;j--){
	        small[j][i]=small[j+1][i];
	        if(a[j]>a[i]) small[j][i]++;
	    }
	}
	for(i=1;i<=n;i++){
	    for(j=i+1;j<=n;j++)
	        small[i][j]+=small[i][j-1];
	}
	for(i=1;i<=n;i++) dp[i][0]=-1;
	for(j=1;j<=k;j++) dp[0][j]=-1;
	for(i=1;i<=n;i++){
	    for(j=1;j<=k;j++){
	        if(j>i){
	            dp[i][j]=-1;
	            continue;
	        }
    	    for(i1=i-1;i1>=0;i1--){
    	        if(dp[i1][j-1]!=-1)
    	            dp[i][j]=max(dp[i][j],dp[i1][j-1]+small[i1+1][i]);
    	    }
	    }
	}
	cout<<dp[n][k];
	return 0;
}
