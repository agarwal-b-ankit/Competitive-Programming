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
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n,i,r,val;
	cin>>n;
	map<ll,ll> m;
	for(i=0;i<n;i++){
        cin>>r;
        while(r--){
            cin>>val;
            m[val]++;
        }
	}
	for(map<ll,ll>::iterator it=m.begin();it!=m.end();it++){
        if(it->ss==n) cout<<it->ff<<" ";
	}
	return 0;
}
