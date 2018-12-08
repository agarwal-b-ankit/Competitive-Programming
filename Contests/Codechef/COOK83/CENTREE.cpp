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
	ll t,n,b,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>b;
        if(b==0)
        {
            if(n==2)
                cout<<"NO\n";
            else
            {
                cout<<"YES\n";
                for(i=2;i<=n;i++)
                    cout<<"1 "<<i<<endl;
            }
        }
        else
        {
            vector<pair<ll,ll> > v;
            for(i=1;i<min(n,2*b+1);i++)
                v.pb(mp(i,i+1));
            if(n<2*b || min(n,2*b+1)-1>n/2)
            {
                cout<<"NO\n";
            }
            else
            {
                for(i=2*b+2;i<=n;i++)
                {
                    v.pb(mp(1,i));
                }
                cout<<"YES\n";
                for(i=0;i<v.size();i++)
                    cout<<v[i].ff<<" "<<v[i].ss<<endl;
            }
        }
	}
	return 0;
}
