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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,i,j,val,fin=0;
	cin>>n;
	vector<ll> ans(n+1,0);
	ans[0]=1;
	for(i=1;i<=n;i++){
        cin>>val;
        vector<pair<ll,ll> > temp;
        for(j=1;j*j<=val;j++){
            if(val%j==0){
                ll fac1=j,fac2=val/j;
                if(fac1<=i){
                    temp.pb(mp(fac1,ans[fac1-1]));
                }
                if(fac1!=fac2 && fac2<=i){
                  temp.pb(mp(fac2,ans[fac2-1]));
                }
            }
        }
        for(pair<ll,ll> tem:temp){
            ans[tem.ff]=(ans[tem.ff]+tem.ss)%mod;
        }
	}
	for(i=1;i<=n;i++) fin=(fin+ans[i])%mod;
	cout<<fin;
	return 0;
}
