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
	ll t,n,a,b,c,i,j,k,ans;
	cin>>t;
	while(t--){
        scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
        map<ll,ll> m;
        vector<ll> ar,br;
        for(i=1;i*i<=n;i++){
            if(n%i!=0)
                continue;
            if(i<=a)
            ar.pb(i);
            if(i<=b)
            br.pb(i);
            if(i<=c)
            m[i]++;
            if(i*i!=n){
                if(n/i<=a)
                ar.pb(n/i);
                if(n/i<=b)
                br.pb(n/i);
                if(n/i<=c)
                m[n/i]++;
            }
        }
        ans=0;
        for(ll ela:ar){
            for(ll elb:br){
                if(n%(ela*elb)==0 && present(m,n/(ela*elb)))
                    ans++;
            }
        }
        printf("%lld\n",ans);
	}
	return 0;
}
