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
#define sca(a) scanf("%lld",&a)
#define sca(a,b) scanf("%lld%lld",&a,&b)
#define sca(a,b,c) scanf("%lld%lld",&a,&b,&c)
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

void solve()
{
    ll i,j,n,k,len,val;
    cin>>n>>k;
    vector<vector<ll> > v(n,vector<ll>(k+1,0));
    vector<vector<ll> > v1(n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&len);
        for(j=0;j<len;j++)
        {
            scanf("%lld",&val);
            v[i][val]=1;
        }
        for(j=1;j<=k;j++)
            if(v[i][j]==0)
                v1[i].pb(j);
    }
    ll ans=0;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            for(k=0;k<v1[i].size();k++)
                if(v[j][v1[i][k]]==0)
                    break;
            if(k==v1[i].size())
                ans++;
        }
    }
    cout<<ans<<endl;
}

int main()
{
	ll t,n,i;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
