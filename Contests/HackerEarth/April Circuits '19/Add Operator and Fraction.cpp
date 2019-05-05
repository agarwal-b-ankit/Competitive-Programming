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
 
ll n,k,cnt=0;
 
void solve(pair<ll,ll> p1, pair<ll,ll> p2){
    if(cnt>=k) return;
    pair<ll,ll> temp={p1.ff+p2.ff,p1.ss+p2.ss};
    if(temp.ss<=n){
        solve(p1,temp);
        solve(temp,p2);
    } else{
        cnt++;
        if(cnt==k){
            cout<<p2.ff<<"/"<<p2.ss;
            return;
        }
    }
}
 
int main()
{
	//FastIO
	ll i;
	cin>>n>>k;
	pair<ll,ll> p1={0,1},p2;
	cnt++;
	if(cnt==k){
        cout<<p1.ff<<"/"<<p1.ss;
        return 0;
    }
	for(i=n;i>=2;i--){
	    p2={1,i};
	    solve(p1,p2);
	    p1=p2;
	}
	return 0;
}