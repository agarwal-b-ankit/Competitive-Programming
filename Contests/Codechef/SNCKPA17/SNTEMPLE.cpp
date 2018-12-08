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

int main()
{
	ll t,n,i;
	cin>>t;
	while(t--)
    {
        cin>>n;
        ll h[n];
        ll sum=0,ans=0;
        for(i=0;i<n;i++)
        {
            cin>>h[i];
            sum+=h[i];
        }
        ll left[n],right[n];
        left[0]=min(1LL,h[0]);
        right[n-1]=min(1LL,h[n-1]);
        for(i=1;i<n;i++)
            left[i]=min(left[i-1]+1,h[i]);
        for(i=n-2;i>=0;i--)
            right[i]=min(right[i+1]+1,h[i]);
        if(h[0]>0 || h[n-1]>0)
            ans=1;
        for(i=1;i<n-1;i++)
            ans=max(ans,min(left[i],right[i]));
        cout<<sum-ans*ans<<endl;
    }
	return 0;
}
