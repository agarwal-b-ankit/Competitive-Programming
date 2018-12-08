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

ll ran[100010],par[100010],dp[1010][1010];

void uni(ll a, ll b)
{
    if(ran[a]<ran[b])
        par[a]=b;
    else par[b]=a;
    if(ran[a]==ran[b])
        ran[a]++;
}

ll fin(ll a)
{
    if(par[a]!=a)
        par[a]=fin(par[a]);
    return par[a];
}

int main()
{
	ll n,i,j,k,m,x,y,val;
	cin>>n>>k>>m;
	ll a[m];
    for(i=0;i<100010;i++)
        par[i]=i;
	while(k--)
    {
        scanf("%lld%lld",&x,&y);
        ll px=fin(x);
        ll py=fin(y);
        if(px!=py)
            uni(px,py);
    }
    for(i=0;i<m;i++)
    {
        cin>>a[i];
        a[i]=fin(a[i]);
    }
    for(i=0;i<m;i++)
        dp[i][i]=1;
    for(ll len=2;len<=m;len++)
    {
        for(i=0;i<m+1-len;i++)
        {
            j=i+len-1;
            if(a[i]==a[j] && len==2)
                dp[i][j]=2;
            else if(a[i]==a[j])
                dp[i][j]=2+dp[i+1][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
        }
    }
    cout<<dp[0][m-1];
	return 0;
}
