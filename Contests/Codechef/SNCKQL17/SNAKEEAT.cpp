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
	ll t,n,q,k,i,pos,low,high,ans;
	cin>>t;
	while(t--)
    {
        cin>>n>>q;
        vector<ll> v(n),pre(n+1);
        vector<ll>::iterator it;
        for(i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        pre[0]=0;
        for(i=0;i<n;i++)
            pre[i+1]=pre[i]+v[i];
        while(q--)
        {
            cin>>k;
            pos=lower_bound(v.begin(),v.end(),k)-v.begin();
            low=0;
            high=pos;
            if(pos==n && n-1>=k-pre[n])
                high=n-1;
            while(low<high && high<n)
            {
                ll mid=(low+high)/2;
                if( (pos-mid)*k-pre[pos]+pre[mid]<=mid)
                    high=mid;
                else low=mid+1;
            }
            cout<<n-high<<endl;
        }
    }
	return 0;
}
