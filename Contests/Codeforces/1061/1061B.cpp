
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
	ll n,m,i,cur,ans=0;
	cin>>n>>m;
	vector<ll> v(n);
	for(i=0;i<n;i++){
        cin>>v[i];
	}
	sort(all(v));
	cur=v[n-1];
	for(i=n-1;i>=0;i--){
        if(cur<1){
            ans+=(v[i]-1);
            continue;
        }
        if(v[i]>cur) ans+=(v[i]-cur);
        if(i>0){
        if(v[i-1]>=cur) cur--;
        else cur=v[i-1];
        ans+=cur;
        }
	}
	cout<<ans;
	return 0;
}
