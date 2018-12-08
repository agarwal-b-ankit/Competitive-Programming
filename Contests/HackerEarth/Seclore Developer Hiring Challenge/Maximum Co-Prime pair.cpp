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
	ll n,val,i,ans=0;
	cin>>n;
	set<ll> sa,sb;
	for(i=0;i<n;i++) {
        cin>>val;
        sa.insert(val);
    }
    for(i=0;i<n;i++) {
        cin>>val;
        sb.insert(val);
    }
    set<ll>::iterator ia,ib;
    for(ia=sa.begin();ia!=sa.end();ia++){
        for(ib=sb.begin();ib!=sb.end();ib++){
            if(__gcd(*ia,*ib)==1) ans=max(ans,*ia+*ib);
        }
    }
    cout<<ans;
	return 0;
}
