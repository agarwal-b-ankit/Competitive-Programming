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
ll P;
 
ll po(ll n, ll p){
    if(p==0) return 1%P;
    ll ans=po(n,p/2);
    ans=(ans*ans)%P;
    if(p%2==1) return (ans*n)%P;
    else return ans;
}
 
ll gpsum(ll r, ll n){
    if(n==1) return 1%P;
    if(n%2==1) return (po(r,n-1)+gpsum(r,n-1))%P;
    else return (gpsum(r,n/2)*((1+po(r,n/2)%P)))%P;
}
 
ll solve(ll n){
    ll ans,ne=n/4,no=n/2;
    if(n==0) return 0;
    else if(n==1) return 1%P;
    else if(n==2) return 2%P;
    else if(n==3) return 5%P;
    else if(n%2==1) return (solve(n-1)+po(3,n/2))%P;
    else if(n%4==0) return (gpsum(3,no)+6*gpsum(9,ne)+2*ne)%P;
    else return (gpsum(3,no)+18*gpsum(9,ne)+2*ne+1)%P;
}
 
int main()
{
	//FastIO
	ll t,l,r,ans;
	cin>>t>>P;
	while(t--)
	{
		cin>>l>>r;
		if(P==1) ans=0;
		else ans=(solve(r)-solve(l-1)+P)%P;
		cout<<ans<<"\n";
	}
	return 0;
}