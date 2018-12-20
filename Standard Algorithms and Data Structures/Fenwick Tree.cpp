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

ll bit[MAXN],a[MAXN],n;

void update(ll ind, ll val){
    while(ind<=n){
        bit[ind]+=val;
        ind+= ind&(-ind);
    }
}

ll query(ll ind){
    ll sum=0;
    while(ind>0){
        sum+=bit[ind];
        ind-= ind&(-ind);
    }
    return sum;
}

int main()
{
	//FastIO
	ll t,i;
	ll temp[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	n=12;
	for(i=1;i<=n;i++) update(i,temp[i-1]);
	cout<<query(5)<<endl;
	update(5,5);
	cout<<query(5)<<endl;
	return 0;
}
