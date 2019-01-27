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

ll po(ll n, ll p, ll MOD){
    if(p==0 || n==1) return 1;
    ll ans=po(n,p/2,MOD);
    if(p%2==0) return (ans*ans)%MOD;
    else return (n*((ans*ans)%MOD))%MOD;
}

ll modInv(ll a, ll MOD){
    return po(a,MOD-2,MOD);
}

ll bit[MAXN],fact[MAXN];

void update(ll ind, ll val){
    while(ind<=MAXN){
        bit[ind]+=val;
        ind+= ind&(-ind);
    }
}

ll query(ll ind){
    ll sum=0;
    while(ind>0){
        sum+=bit[ind];
        ind-= ind&(-ind);
    }
    return sum;
}

void processFact(ll n){
    fact[1]=1;
    for(ll i=2;i<=n;i++)
        fact[i]=(fact[i-1]*i)%mod;
}

ll cal(ll a, ll b, ll c, ll m){
    return ((((a%m)*(b%m))%m)*modInv(c,m))%m;
}

ll getRank(vector<ll> &a){
    processFact(MAXN);
    memset(bit,0,sizeof(bit));
    map<ll,ll> fre;
    ll i,n=a.size();
    for(i=0;i<n;i++)
	    fre[a[i]]++;
	ll tot=fact[n],ans=0;
	for(auto e:fre){
	    update(e.ff,e.ss);
	    tot=cal(tot,1,fact[e.ss],mod);
	}
	for(i=0;i<n;i++){
	    ll sum=query(a[i]-1);
	    ans=(ans+cal(tot,sum,n-i,mod))%mod;
        tot=cal(tot,fre[a[i]],n-i,mod);
	    update(a[i],-1);
	    fre[a[i]]--;
	}
	return (ans+1)%mod;
}

int main()
{
	FastIO
	vector<ll> a{4, 4, 2, 2, 1};
    cout<<getRank(a)<<"\n";
	return 0;
}
