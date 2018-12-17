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

ll a[MAXN],b[MAXN],n;

bool solve(){
    ll i,cnt=0;
    map<ll,vector<ll>> m;
	for(i=0;i<n;i++){
        m[a[i]].pb(i);
	}
	for(auto v:m){
        if(v.ss.size()%v.ff!=0) return false;
        for(i=0;i<v.ss.size();i++){
            if(i%v.ff==0) cnt++;
            b[v.ss[i]]=cnt;
        }
	}
    return true;
}

int main()
{
	//FastIO
	ll t,i;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) a[i]=n-a[i];
	bool flag=solve();
    if(flag) cout<<"Possible\n";
    else cout<<"Impossible\n";
    if(flag) for(i=0;i<n;i++) cout<<b[i]<<" ";
	return 0;
}
