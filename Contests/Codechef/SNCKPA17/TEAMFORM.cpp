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
	ll n,m,u,v,t;
	cin>>t;
	while(t--)
    {
        cin>>n>>m;
        ll k=m;
        while(k--)
            cin>>u>>v;
        if((n-2*m)%2==0)
            cout<<"yes\n";
        else cout<<"no\n";
    }
	return 0;
}
