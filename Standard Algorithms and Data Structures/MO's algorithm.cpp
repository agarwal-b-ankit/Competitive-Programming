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

pair<pair<ll,ll>,ll> q[MAXN];
ll BLOCK,a[MAXN],ans[MAXN],sum=0;

bool cmp(pair<pair<ll,ll>,ll> p1, pair<pair<ll,ll>,ll> p2){
    if(p1.ff.ff/BLOCK!=p2.ff.ff/BLOCK)
        return p1.ff.ff/BLOCK<p2.ff.ff/BLOCK;
    return p1.ff.ss<p2.ff.ss;
}

void add(ll pos){
    sum+=a[pos];
}

void rem(int pos){
    sum-=a[pos];
}

void solve(ll n){
	ll curL=0,curR=0;
    BLOCK=sqrt(n);
	sort(q,q+n,cmp);
	for(ll i=0;i<n;i++){
        ll L=q[i].ff.ff,R=q[i].ff.ss;
        while(curL<L){
            rem(curL);
            curL++;
        }
        while(curL>L){
            add(curL-1);
            curL--;
        }
        while(curR<=R){
            add(curR);
            curR++;
        }
        while(curR>R+1){
            rem(curR-1);
            curR--;
        }
        ans[q[i].ss]=sum;
	}
}

// Code to get sum of elements in a given range of queries
int main()
{
	//FastIO
	ll t,n,i;
	n=3;
	a[0]=1;a[1]=1;a[2]=2;a[3]=1;a[4]=3;
	q[0]=mp(mp(0,4),0);
	q[1]=mp(mp(1,3),1);
	q[2]=mp(mp(2,4),2);
	solve(n);
	for(i=0;i<n;i++) cout<<ans[i]<<" ";
	return 0;
}
