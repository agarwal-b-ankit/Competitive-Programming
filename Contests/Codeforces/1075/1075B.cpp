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
	ll n,m,i,flag;
	cin>>n>>m;
	vector<int> v(n+m),taxi,res;
	for(i=0;i<n+m;i++) cin>>v[i];
	for(i=0;i<n+m;i++){
        cin>>flag;
        if(flag==1) taxi.pb(v[i]);
        else res.pb(v[i]);
	}
	map<ll,ll> cnt;
	for(i=0;i<res.size();i++){
        ll lb=lower_bound(taxi.begin(),taxi.end(),res[i])-taxi.begin();
        if(lb==0){
            cnt[lb]++;
        } else if(lb==taxi.size()) cnt[lb-1]++;
        else{
            if(res[i]-taxi[lb-1]<=taxi[lb]-res[i])
                cnt[lb-1]++;
            else cnt[lb]++;
        }
	}
	for(i=0;i<m;i++)
        cout<<cnt[i]<<" ";
	return 0;
}
