#include <bits/stdc++.h>
using namespace std;
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

int main()
{
	ll t,n,x,y,i,ans=0,l,r,tv=0,cur=0;
	cin>>n>>x>>y;
	vector<pair<ll,ll> > v(n);
	for(i=0;i<n;i++){
        scanf("%lld%lld",&l,&r);
        v[i].ff=l;v[i].ss=r;
        ans=(ans+(y*(v[i].ss-v[i].ff))%mod)%mod;
	}
	sort(all(v));
	multiset<ll> s;
	for(pair<ll,ll> pi: v){
        if(s.empty()){
            s.insert(pi.ss);
            ans=(ans+x)%mod;
        } else{
            auto it=s.lower_bound(pi.ff);
            if(it!=s.begin()){
                it--;
                ll val1=y*(pi.ff-*it);
                if(val1<x){
                    s.erase(it);
                    ans=(ans+val1)%mod;
                } else ans=(ans+x)%mod;
                s.insert(pi.ss);
            } else{
                s.insert(pi.ss);
                ans=(ans+x)%mod;
            }
        }
	}
	cout<<ans;
	return 0;
}
