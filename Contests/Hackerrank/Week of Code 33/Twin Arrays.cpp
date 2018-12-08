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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll n,i;
    cin>>n;
    vector<pair<ll,ll> > a,b;
    pair<ll,ll> temp;
    for(i=0;i<n;i++)
        {
        cin>>temp.ff;
        temp.ss=i;
        a.pb(temp);
    }
    for(i=0;i<n;i++)
        {
        cin>>temp.ff;
        temp.ss=i;
        b.pb(temp);
    }
    sort(all(a));
    sort(all(b));
    if(a[0].ss!=b[0].ss)
        cout<<a[0].ff+b[0].ff;
    else cout<<min(a[0].ff+b[1].ff,a[1].ff+b[0].ff);

    return 0;
}
