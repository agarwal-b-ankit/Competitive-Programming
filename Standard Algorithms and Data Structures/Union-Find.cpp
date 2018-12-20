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

ll par[MAXN],ran[MAXN];

void init(ll n){
    for(ll i=0;i<n;i++){
        par[i]=i;
        ran[i]=1;
    }
}

ll fin(ll x){
    if(par[x]!=x)
        par[x]=fin(par[x]);
    return par[x];
}

void uni(ll x, ll y){
    ll px=fin(x),py=fin(y);
    if(px==py) return;
    if(ran[px]<ran[py]){
        par[px]=py;
        ran[py]+=ran[px];
    }
    else{
        par[py]=px;
        ran[px]+=ran[py];
    }
}

int main()
{
	//FastIO
	init(MAXN);
	ll t,n,i;
	uni(1,2);
	uni(2,3);
	uni(1,4);
	uni(4,5);
	uni(7,6);
	uni(7,8);
	for(i=1;i<=8;i++){
        par[i]=fin(i);
        cout<<"parent of "<<i<<" is "<<par[i]<<" ans size of component is "<<ran[par[i]]<<endl;
    }
    uni(3,6);
    for(i=1;i<=8;i++){
        par[i]=fin(i);
        cout<<"parent of "<<i<<" is "<<par[i]<<" ans size of component is "<<ran[par[i]]<<endl;
    }
	return 0;
}
