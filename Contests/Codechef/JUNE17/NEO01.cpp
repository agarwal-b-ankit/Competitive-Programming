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
		ll sum=0,cnt=0,ans=0;
		vector<ll> v(n);
		for(i=0;i<n;i++)
            cin>>v[i];
        sort(all(v));
        reverse(all(v));
        for(i=0;i<v.size();i++)
        {
            if((sum+v[i])*(cnt+1)>=sum*cnt+v[i])
            {
                sum+=v[i];
                cnt++;
            }
            else
                break;
        }
        ans=sum*cnt;
        for(;i<v.size();i++)
            ans+=v[i];
        cout<<ans<<endl;
	}
	return 0;
}
