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
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

ll getNum(ll n, ll m, ll i){
    ll ans=n/m;
    if(i<=n%m) ans++;
    return ans;
}

int main()
{
	//FastIO
	ll n,m,i,j,ans=0;
	cin>>n>>m;
	for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            if((i*i+j*j)%m==0){
                ans+=getNum(n,m,i)*getNum(n,m,j);
            }
        }
	}
	cout<<ans;
	return 0;
}
