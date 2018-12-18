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
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

ll ask(ll i, ll j, ll k){
    cout<<"1 "<<i<<" "<<j<<" "<<k<<endl<<flush;
    ll val;
    cin>>val;
    return val;
}

void solve(){
    ll n,i,wrong,abc,abd,com,last2,last1;
    cin>>n;
    vector<ll> ans(n+1,2);
    abc=ask(1,2,3);
    abd=ask(1,2,4);
    com=abc^abd;
    last2=3;
    last1=4;
    for(i=5;i<n;i+=2){
        tie(ans[i],ans[i+1])=make_tuple(com^ask(last1,last2,i),com^ask(last1,last2,i+1));
        com=ans[i]^ans[i+1];
        last2=i;
        last1=i+1;
    }
    if(i==n){
        ans[n]=ans[n-2]^ans[n-1]^ask(n-2,n-1,n);
        ans[1]=ans[n-2]^ans[n]^ask(1,n-2,n);
        ans[2]=ans[n-1]^ans[n]^ask(2,n-1,n);
    } else{
        ans[1]=ans[n-1]^ans[n]^ask(1,n-1,n);
        ans[2]=ans[n-1]^ans[n]^ask(2,n-1,n);
    }
    ans[3]=abc^ans[1]^ans[2];
    ans[4]=abd^ans[1]^ans[2];
    for(i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl<<flush;
    cin>>wrong;
    if(wrong==-1){
        exit(0);
    }
}

int main()
{
	//FastIO
	ll t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
