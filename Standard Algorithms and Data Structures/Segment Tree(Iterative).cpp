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

ll tree[MAXN],a[MAXN],n;

void build(){
    for(ll i=0;i<n;i++) tree[i+n]=a[i];
    for(ll i=n-1;i>0;i--) tree[i]=tree[i<<1]+tree[1<<1|1];
}

void update(ll ind, ll val){
    tree[ind+n]+=val;
    ind+=n;
    for(;ind>1;ind>>=1) tree[ind>>1]=tree[ind]+tree[ind^1];
}

ll query(ll l, ll r){
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}

int main()
{
	//FastIO
	ll t,i;
	ll temp[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	for(i=0;i<12;i++) a[i]=temp[i];
	n=12;
	build();
	cout<<query(1,3)<<endl; // [1,3) 0-based
	update(2,1);
	cout<<query(1,3)<<endl;
	return 0;
}
