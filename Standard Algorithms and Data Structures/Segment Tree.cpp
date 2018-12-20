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

ll tree[MAXN],a[MAXN];

void build(ll node, ll s, ll e){
    if(s==e){
        tree[node]=a[s];
        return;
    }
    ll mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    tree[node]=tree[2*node]+tree[2*node+1];
}

void update(ll node, ll s, ll e, ll ind, ll val){
    if(s==e){
        tree[node]+=val;
        return;
    }
    ll mid=(s+e)/2;
    if(ind>=s && ind<=mid){
        update(2*node,s,mid,ind,val);
    } else{
        update(2*node+1,mid+1,e,ind,val);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}

void updateRange(ll node, ll s, ll e, ll l, ll r, ll val){
    if(r<s || l>e) return;
    if(s==e){
        tree[node]+=val;
        return;
    }
    ll mid=(s+e)/2;
    updateRange(2*node,s,mid,l,r,val);
    updateRange(2*node+1,mid+1,e,l,r,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(ll node, ll s, ll e, ll l, ll r){
    if(r<s || l>e) return 0;
    if(s>=l && e<=r) return tree[node];
    ll mid=(s+e)/2;
    ll p1=query(2*node,s,mid,l,r),p2=query(2*node+1,mid+1,e,l,r);
    return p1+p2;
}

int main()
{
	//FastIO
	ll t,n,i;
	ll temp[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	for(i=0;i<12;i++) a[i]=temp[i];
	build(1,0,11);
	cout<<query(1,0,11,0,2)<<endl;
	update(1,0,11,1,8);
	cout<<query(1,0,11,0,2)<<endl;
	return 0;
}
