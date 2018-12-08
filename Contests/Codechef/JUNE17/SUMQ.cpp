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

void preSum(vector<ull> &a,vector<ull> &prea)
{
    for(ll i=0;i<a.size();i++)
    {
        if(i==0)
            prea.pb(a[i]);
        else prea.pb(prea[i-1]+a[i]);
        prea[i]%=mod;
    }
}

int main()
{
	ull t,p,q,r,i;
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld%lld",&p,&q,&r);
		vector<ull> a(p),b(q),c(r),prea,prec;
		ull ans=0,sum=0,prod=0;
		for(i=0;i<p;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<q;i++)
            scanf("%lld",&b[i]);
        for(i=0;i<r;i++)
            scanf("%lld",&c[i]);

        sort(all(a));
        sort(all(b));
        sort(all(c));

        preSum(a,prea);
        preSum(c,prec);

        for(i=0;i<b.size();i++)
        {
            ll posa=upper_bound(a.begin(),a.end(),b[i])-a.begin();
            ll posc=upper_bound(c.begin(),c.end(),b[i])-c.begin();
            if(posa==0 || posc==0)
                continue;
            sum=((posa*prec[posc-1])%mod+(posc*prea[posa-1])%mod)%mod;
            prod=(prea[posa-1]*prec[posc-1])%mod;
            ans+=(((((posa*posc)%mod)*((b[i]*b[i])%mod))%mod+(b[i]*sum)%mod+prod)%mod);
            ans%=mod;
        }
        cout<<ans<<endl;
	}
	return 0;
}
