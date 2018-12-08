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
	ll n,i,ans=0;
	string s,sr;
	cin>>n;
	map<string,ll> m;
	map<string,ll>::iterator it;
	for(i=0;i<n;i++){
        cin>>s;
        m[s]++;
	}
	for(it=m.begin();it!=m.end();it++){
	    s=it->first;
	    sr=it->first;
	    reverse(all(sr));
	    if(s.compare(sr)==0) continue;
	    else if(present(m,sr)) ans+=min(m[sr],it->second);
	}
	cout<<ans/2;
	return 0;
}
