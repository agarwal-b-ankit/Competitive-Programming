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
const ll MAXN=200010;

ll a[MAXN];

bool solve(ll n){
    stack<ll> s;
    ll h=0;
	for(ll i=0;i<n;i++){
        if(s.empty() || s.top()>a[i]){
            s.push(a[i]);
        } else if(s.top()==a[i]){
            s.pop();
            h=max(h,a[i]);
        } else return false;
	}
	return s.empty() || (s.size()==1 && s.top()>=h);
}

int main()
{
	//FastIO
	ll n,i;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	if(solve(n)) cout<<"YES";
	else cout<<"NO";
	return 0;
}
