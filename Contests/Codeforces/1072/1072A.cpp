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
	ll w,h,k,ans=0;
	cin>>w>>h>>k;
	ll w1=max(w,h);
	h=min(w,h);
	w=w1;
	for(h;h>2 && w>2 && k>0;h-=4,w-=4,k--){
        ans+=(w*h-((w-2)*(h-2)));
	}
	cout<<ans;
	return 0;
}
