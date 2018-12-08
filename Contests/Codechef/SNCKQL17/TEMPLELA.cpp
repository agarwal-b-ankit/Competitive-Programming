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
	ll s,n,i;
	cin>>s;
	while(s--)
    {
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            if(a[i]!=min(i+1,n-i))
                break;
        }
        if(i!=n || n%2==0)
            cout<<"no\n";
        else cout<<"yes\n";
    }
	return 0;
}
