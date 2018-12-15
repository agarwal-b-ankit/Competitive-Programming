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
const ll MAXN=1000001;

ll a[50001],n,mask;
vector<ll> p[MAXN];
ll dp[50001][256];
map<ll,ll> mx;

void sieve(){
    for(ll i=2;i<MAXN;i++){
        if(p[i].size()==0){
            p[i].pb(i);
            for(ll j=i*2;j<MAXN;j+=i){
                p[j].pb(i);
            }
        }
    }
}

ll solve(ll ind, ll cmask){
    if(ind==n){
        if(cmask==mask) return 1;
        else return 0;
    }
    if(dp[ind][cmask]!=-1) return dp[ind][cmask];
    ll ans=solve(ind+1,cmask);
    if(a[ind]!=-1)
        ans+=solve(ind+1,cmask|a[ind]);
    ans%=mod;
    return dp[ind][cmask]=ans;
}

ll getMask(ll val){
    ll mask=0;
    for(ll e:p[val]){
        if(!present(mx,e)){
            mask=-1;
            break;
        } else mask|=(1<<mx[e]);
    }
    return mask;
}

int main()
{
	//FastIO
	sieve();
	ll t,i,x,val;
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld",&n,&x);
		memset(dp,-1,sizeof(dp));
		mx.clear();
		ll cnt=0;
		for(ll e:p[x])
            mx[e]=cnt++;
		mask=(1<<cnt)-1;
		for(i=0;i<n;i++){
		    scanf("%lld",&val);
		    a[i]=getMask(val);
		}
		printf("%lld\n",solve(0,0));
	}
	return 0;
}
