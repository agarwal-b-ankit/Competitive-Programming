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
	ll n,m,i,j,i1,j1,even,ans=0;
	cin>>n>>m;
	string a[n];
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	for(i=0;i<n-7;i++){
	    for(j=0;j<m-7;j++){
	        even=a[i][j]-'0';
	        if((i+j)%2==1){
	            even=1-even;
	        }
	        bool valid=true;
	        for(i1=i;i1<i+8;i1++){
	            for(j1=j;j1<j+8;j1++){
	                if((i1+j1)%2==0 && (a[i1][j1]-'0')!=even){
	                    valid=false;
	                }
	                if((i1+j1)%2==1 && (a[i1][j1]-'0')==even) valid=false;
	            }
	        }
	        if(valid) ans++;
	    }
	}
	cout<<ans;
	return 0;
}
