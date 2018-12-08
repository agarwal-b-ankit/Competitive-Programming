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

ll n,l,a,b;

ll fun(ll val, vector<pair<ll,ll> > &v)
{
    ll ans=0;
    for(ll i=0;i<v.size();i++)
        ans+=abs(v[i].ff-(val+i*l));
    return ans;
}

ll findPeak(vector<pair<ll,ll> > &v, int low, int high)
{
    ll mid = low + (high - low)/2;  /* (low + high)/2 */
    if ((mid == a || fun(mid-1,v) >= fun(mid,v)) &&
            (mid == b || fun(mid+1,v) >= fun(mid,v)))
        return mid;
    else if (mid > 0 && fun(mid-1,v) > fun(mid,v))
        return findPeak(v, mid+1, high);
    else return findPeak(v, low, (mid -1));
}


int main()
{
	ll t,i;
	cin>>t;
	while(t--)
    {
        cin>>n>>l>>a>>b;
        b=b-n*l;
        vector<pair<ll,ll> > v(n);
        for(i=0;i<n;i++)
        {
            cin>>v[i].ff;
            v[i].ss=v[i].ff+l;
        }
        sort(v.begin(),v.end());
        ll peak=findPeak(v,a,b);
        cout<<fun(peak,v)<<endl;
    }
	return 0;
}
