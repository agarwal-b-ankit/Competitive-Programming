#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
	ll t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll minx=INF,miny=INF,maxx=0,maxy=0,ans=INF,lx,ly,rx,ry;
		vector<pair< pair<ll,ll>, pair<ll,ll> > > v;
		for(i=0;i<n;i++)
        {
            cin>>lx>>ly>>rx>>ry;
            minx=min(minx,min(lx,rx));
            maxx=max(maxx,max(lx,rx));
            miny=min(miny,min(ly,ry));
            maxy=max(maxy,max(ly,ry));
            v.pb(mp(mp(min(lx,rx),min(ly,ry)),mp(max(lx,rx),max(ly,ry))));
        }
        for(i=minx;i<=maxx;i++)
        {
            for(j=miny;j<=maxy;j++)
            {
                ll temp1=0;
                for(k=0;k<n;k++)
                {
                    ll temp=0;
                    if(v[k].ff.ss==v[k].ss.ss)
                    {
                        temp+=abs(v[k].ff.ss-j);
                        if(i<v[k].ff.ff)
                            temp+=v[k].ff.ff-i;
                        else if(i>v[k].ss.ff)
                            temp+=i-v[k].ss.ff;
                    }
                    else
                    {
                        temp+=abs(v[k].ff.ff-i);
                        if(j<v[k].ff.ss)
                            temp+=v[k].ff.ss-j;
                        else if(j>v[k].ss.ss)
                            temp+=j-v[k].ss.ss;
                    }
                    temp1=max(temp1,temp);
                }
                ans=min(ans,temp1);
            }
        }
        cout<<ans<<endl;

	}
	return 0;
}
