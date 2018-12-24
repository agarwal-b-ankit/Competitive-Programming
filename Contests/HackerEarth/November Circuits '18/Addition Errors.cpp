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
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t,n,a,b,i;
	cin>>t;
	while(t--){
        cin>>a>>b;
        ll ans=0,mul=10;
        while(a>0 && b>0){
            if(a%10+b%10>9) ans+=mul;
            a/=10;
            b/=10;
            mul*=10;
        }
        cout<<ans<<endl;
	}
	return 0;
}
