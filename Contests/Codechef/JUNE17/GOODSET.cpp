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

ll good[501];
vector<ll> ele;

void solve()
{
    good[3]=1;
    ele.pb(1);
    ele.pb(2);
    for(ll i=4;i<501;i++)
    {
        if(good[i]==1)
            continue;
        ele.pb(i);
        for(ll j=1;j<i;j++)
            if(good[j]==0 && i+j<501)
                good[i+j]=1;
    }
}

int main()
{
	ll t,n,i;
	cin>>t;
	solve();
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
            cout<<ele[i]<<" ";
        cout<<endl;
	}
	return 0;
}
