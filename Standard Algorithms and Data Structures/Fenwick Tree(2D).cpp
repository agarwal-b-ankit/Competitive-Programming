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
const ll MAXN=1010;

ll bit[MAXN][MAXN],a[MAXN][MAXN];

void update(ll x, ll y, ll val, ll n, ll m){
    while(x<=n){
        ll y1=y;
        while(y1<=m){
            bit[x][y1]+=val;
            y1+= y1&(-y1);
        }
        x+= x&(-x);
    }
}

ll query(ll x, ll y){
    ll sum=0;
    while(x>0){
        ll y1=y;
        while(y1>0){
            sum+=bit[x][y1];
            y1-= y1&(-y1);
        }
        x-= x&(-x);
    }
    return sum;
}

int main()
{
	//FastIO
	// 1 2 3 4
	// 5 6 7 8
	// 1 7 5 9
	// 3 0 6 2
	ll n,m,i,j,lx=0,ly=0,rx,ry;
	cin>>n>>m;
	rx=n-1,ry=m-1;
	for(i=lx;i<=rx;i++)
	    for(j=ly;j<=ry;j++){
	        cin>>a[i][j];
	        update(i+1,j+1,a[i][j],n,m);
	    }
	cout<<query(4,4)<<endl;
	update(1,2,8,n,m);
	update(2,3,8,n,m);
	update(3,3,8,n,m);
	cout<<query(4,4)-query(2,2)<<endl;
	return 0;
}
