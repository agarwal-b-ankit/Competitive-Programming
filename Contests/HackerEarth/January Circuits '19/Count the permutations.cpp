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

void process(){
    fact[1]=1;
    for(ll i=2;i<=MAXN;i++)
        fact[i]=(fact[i-1]*i)%mod;
}

ll po(ll n, ll p){
    if(p==0) return 1;
    ll ans=po(n,p/2);
    if(p%2==0) return (ans*ans)%mod;
    else return (n*((ans*ans)%mod))%mod;
}

ll modInv(ll a, ll b){
    return ((a%mod)*po(b,mod-2))%mod;
}

int main()
{
	FastIO
	process();
	ll n,i,pos,ans=0;
	cin>>n;
	vector<ll> a(n),b(n);
	map<ll,ll> fre;
	for(i=0;i<n;i++){
	    cin>>a[i];
	    fre[a[i]]++;
	}
	for(i=0;i<n;i++)
	    cin>>b[i];
	ll cal=fact[n];
	for(auto e:fre){
	    update(e.ff,e.ss);
	    cal=modInv(cal,fact[e.ss]);
	}
	for(i=0,pos=n;i<n;i++,pos--){
	    ll sum=query(b[i])-fre[b[i]];
	    ans=(ans+modInv(cal*sum,pos))%mod;
	    if(fre[b[i]]<=0)
	        break;
	    cal=modInv(cal*fre[b[i]],pos);
	    update(b[i],-1);
	    fre[b[i]]--;
	}
	cout<<ans;
	return 0;
}
