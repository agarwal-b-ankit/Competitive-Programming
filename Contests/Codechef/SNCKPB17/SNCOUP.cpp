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
	ll t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		char c[n];
		ll cnt=0;
		vector<pair<ll,ll> > v,v1;
		for(i=0;i<2;i++)
		{
		    ll tmp=0;
		    bool is=false;
		    ll l=0,r=0;
		    for(j=0;j<n;j++)
            {
                cin>>c[j];
                if(c[j]=='*')
                {
                    tmp++;
                    if(is)
                    {
                        r=j;
                        if(i==0)
                        v.pb(mp(l,r));
                        else
                        v1.pb(mp(l,r));
                    }
                    l=j+1;
                    is=true;
                }
            }
            if(tmp>0)
                cnt++;
		}
		ll ans=0;
		if(cnt>1)
            ans++;
        sort(all(v));
        sort(all(v1));
        i=0;
        j=0;
        while(i<v.size() && j<v1.size())
        {
            if(v[i].ss<v1[j].ff)
            {
                ans++;
                i++;
            }
            else if(v1[j].ss<v[i].ff)
            {
                ans++;
                j++;
            }
            else
            {
                ans++;
                i++;
                j++;
            }
        }
        while(i<v.size())
        {
            ans++;
            i++;
        }
        while(j<v1.size())
        {
            ans++;
            j++;
        }
        cout<<ans<<endl;
	}
	return 0;
}
