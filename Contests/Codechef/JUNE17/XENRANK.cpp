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
	ll t,u,v,i;
	cin>>t;
	while(t--)
	{
		cin>>u>>v;
		unsigned long long ans=0;
		ans=u+v;
		if(ans%2==0)
            ans=(ans/2)*(ans+1);
        else ans=ans*((ans+1)/2);
        ans+=u+1;
        cout<<ans<<endl;
	}
	return 0;
}
