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
ll INF=1e9;
const ll MAXN=100010, N=33;

struct Node{
    int M[N][N];
    int ans;
};

ll v[MAXN],res[N],tmp[N];
struct Node tree[3*MAXN];

struct Node merge(struct Node &a, struct Node &b){
    struct Node temp;
    ll i,j,k;
    for(i=1;i<N;i++)
        for(j=1;j<N;j++)
            temp.M[i][j]=INF;
    temp.ans=INF;
    for(i=1;i<N;i++){
        for(j=i;j<N;j++){
            for(k=j;k<N;k++){
                temp.M[i][k]=min(temp.M[i][k],a.M[i][j]+b.M[j][k]);
                temp.ans=min(temp.ans,temp.M[i][k]);
            }
        }
    }
    return temp;
}

void build(ll node, ll s, ll e){
    if(s==e){
        tree[node].ans=INF;
        for(ll i=1;i<N;i++){
            for(ll j=i;j<N;j++){
                if(i<=v[s] && v[s]<=j) tree[node].M[i][j]=0;
                else if(v[s]<i) tree[node].M[i][j]=i-v[s];
                else tree[node].M[i][j]=v[s]-j;
                tree[node].ans=min(tree[node].ans,tree[node].M[i][j]);
            }
        }
        return;
    }
    ll mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    tree[node]=merge(tree[2*node],tree[2*node+1]);
}

void query(ll node, ll s, ll e, ll l, ll r){
    if(r<s || l>e) return;
    if(s>=l && e<=r) {
        for(ll i=1;i<N;i++)
            tmp[i]=res[i],res[i]=INF;
        for(ll i=1;i<N;i++){
            for(ll j=i;j<N;j++)
                res[j]=min(res[j],tmp[i]+tree[node].M[i][j]);
        }
        return;
    }
    ll mid=(s+e)/2;
    if(l<=mid)
        query(2*node,s,mid,l,r);
    if(r>mid)
        query(2*node+1,mid+1,e,l,r);
}

int main()
{
	FastIO
	ll n,q,a,b,i,j,last=0;
	cin>>n>>q;
	for(i=0;i<n;i++)
	    cin>>v[i];
	build(1,0,n-1);
	while(q--){
	    cin>>a>>b;
        a=(a+last-1)%n;
        b=(b+last-1)%n;
	    memset(res,0,sizeof(res));
	    query(1,0,n-1,a,b);
	    last=INF;
	    for(i=1;i<N;i++) last=min(last,res[i]);
	    cout<<last<<"\n";
	}
	return 0;
}
