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

ll p[1050];
vector<ll> valid;

void sieve(){
    ll i,j;
    for(i=2;i<1050;i++) p[i]=1;
    for(i=2;i<1050;i++)
        if(p[i]==1){
            valid.pb(i*i);
            for(j=i*2;j<1050;j+=i)
                p[j]=0;
        }
}

int main()
{
	//FastIO
	sieve();
	ll n,k,i;
	cin>>n>>k;
	vector<ll> a(n),diff(n);
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++){
	    diff[i]=INF;
	    ll ub=lower_bound(all(valid),a[i])-valid.begin();
	    if(ub>0) diff[i]=min(diff[i],a[i]-valid[ub-1]);
	    diff[i]=min(diff[i],valid[ub]-a[i]);
	}
	sort(all(diff));
	ll ans=0;
	for(i=0;i<k;i++){
	    ans+=diff[i];
	}
	ans+=n-k;
	cout<<ans;
	return 0;
}
