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
	ll n,m,i,j,ans=0;
	cin>>n>>m;
	vector<string> s(n);
	for(i=0;i<n;i++)
	    cin>>s[i];
	for(i=0;i<n;i++){
	    for(j=0;j<m;j++){
	        if(i<n-3 && j<m-3 && s[i][j]=='s' && s[i+1][j+1]=='a' && s[i+2][j+2]=='b' && s[i+3][j+3]=='a')
	            ans++;
	        if(i>2 && j<m-3 && s[i][j]=='s' && s[i-1][j+1]=='a' && s[i-2][j+2]=='b' && s[i-3][j+3]=='a')
	            ans++;
	        if(j<m-3 && s[i][j]=='s' && s[i][j+1]=='a' && s[i][j+2]=='b' && s[i][j+3]=='a')
	            ans++;
	        if(i<n-3 && s[i][j]=='s' && s[i+1][j]=='a' && s[i+2][j]=='b' && s[i+3][j]=='a')
	            ans++;
	    }
	}
	cout<<ans;
	return 0;
}