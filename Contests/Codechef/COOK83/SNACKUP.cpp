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
	ll t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<n<<endl;
		vector<pair<ll,ll> > v(n);
		for(i=0;i<n;i++)
		{
		    v[i].ff=i+1;
		    v[i].ss=i+2;
		    if(v[i].ss==n+1)
                v[i].ss=1;
		}
		for(ll k=0;k<n;k++)
        {
            cout<<n<<endl;
            for(i=0;i<n;i++)
            {
                ll j=(i+k)%n;
                cout<<i+1<<" "<<v[j].ff<<" "<<v[j].ss<<endl;
            }
        }
	}
	return 0;
}
