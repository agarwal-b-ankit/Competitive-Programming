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

void solve(ll e, ll extra, vector<ll> &ans){
    if(extra==0){
        ans.pb(e);
        return;
    }
    extra--;
    if(extra>=e/2-1){
        for(ll i=0;i<e/2;i++) ans.pb(1);
        extra-=e/2-1;
    } else ans.pb(e/2);
    solve(e/2,extra,ans);
}

int main()
{
	//FastIO
	ll n,n1,k,i;
	cin>>n>>k;
	n1=n;
	vector<ll> v,ans;
    ll cnt=0;
    while(n1>0){
        if(n1%2==1) v.pb(pow(2,cnt));
        n1/=2;
        cnt++;
    }
    if(k>n || k<v.size()){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    ll extra=k-v.size();
    for(auto e:v){
        if(extra==0) ans.pb(e);
        else if(extra>=e-1){
            for(i=0;i<e;i++) ans.pb(1);
            extra=extra-e+1;
        } else{
            solve(e,extra,ans);
            extra=0;
        }
    }
    for(auto e:ans) cout<<e<<" ";
	return 0;
}
