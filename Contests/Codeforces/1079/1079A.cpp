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
	ll n,k,val,i,sum=0,ma=0,siz;
	map<ll,ll> m;
	cin>>n>>k;
	for(i=0;i<n;i++){
        cin>>val;
        m[val]++;
	}
	siz=m.size();
	for(map<ll,ll>::iterator it=m.begin();it!=m.end();it++){
        ma=max(ma,it->second);
        sum+=it->second;
	}
	if(ma%k!=0) ma=k*(ma/k+1);
	cout<<ma*siz-sum;

	return 0;
}
