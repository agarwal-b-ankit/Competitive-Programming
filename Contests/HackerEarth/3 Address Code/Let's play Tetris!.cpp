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
const ll MAXN=400010;
 
ll tree[MAXN],lazy[MAXN],a[MAXN];
 
void updateRange(ll node, ll s, ll e, ll l, ll r, ll val){
    if(lazy[node]!=0){
        tree[node]=lazy[node];
        if(s!=e){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(s>e || r<s || l>e) return;
    if(s>=l && e<=r){
        tree[node]=val;
        if(s!=e){
            lazy[2*node]=val;
            lazy[2*node+1]=val;
        }
        return;
    }
    ll mid=(s+e)/2;
    updateRange(2*node,s,mid,l,r,val);
    updateRange(2*node+1,mid+1,e,l,r,val);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
 
ll query(ll node, ll s, ll e, ll l, ll r){
    if(s>e || r<s || l>e) return 0;
    if(lazy[node]!=0){
        tree[node]=lazy[node];
        if(s!=e){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(s>=l && e<=r) return tree[node];
    ll mid=(s+e)/2;
    ll p1=query(2*node,s,mid,l,r),p2=query(2*node+1,mid+1,e,l,r);
    return max(p1,p2);
}
 
void reset(){
    for(ll i=0;i<MAXN;i++){
        tree[i]=0;
        lazy[i]=0;
        a[i]=0;
    }
}
 
int main()
{
	//FastIO
	ll t,n,q,i,t1,l,r;
	cin>>t;
	while(t--)
	{
	    reset();
		cin>>n>>q;
		while(q--){
		    cin>>t1>>l>>r;
		    if(t1==0){
		        cout<<query(1,0,n-1,l-1,r-1)<<"\n";
		    }else{
		        ll val=query(1,0,n-1,l-1,l+r-1);
		        updateRange(1,0,n-1,l-1,l+r-1,val+r);
		    }
		}
	}
	return 0;
}