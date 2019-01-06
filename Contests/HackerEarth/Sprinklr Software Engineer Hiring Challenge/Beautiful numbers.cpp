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

ll po2[70],ans[70];

ll solve(ll n){
    if(n==0) return 0;
    ll p=log2(n);
    ll extra=n-po2[p];
    return ans[p]+extra+solve(extra);
}

ll findAns(ll x){
    ll low=1,high=1e17,mid;
    high=min(high,x);
    while(low<high){
        mid=(low+high)/2;
        ll temp=solve(mid);
        if(temp<x) low=mid+1;
        else high=mid;
        if(temp==x) break;
    }
    return high;
}

void preprocess(){
    po2[0]=1,ans[0]=1;
    for(ll i=2,cnt=1;i<=1e18;i*=2,cnt++){
        po2[cnt]=i;
        ans[cnt]=2*ans[cnt-1]+i/2-1;
    }
}

int main()
{
	FastIO
	preprocess();
	ll t,x;
	cin>>t;
	while(t--){
		cin>>x;
		cout<<findAns(x)<<"\n";
	}
	return 0;
}
