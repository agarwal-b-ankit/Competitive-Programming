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
ll dp[101][1024];
ll all=0;

void reset(){
    memset(dp, -1, sizeof(dp[0][0]) * 101 * 1024);
    all=0;
}

ll solve(vector<vector<ll> > &v, ll ind, ll mask){
    if(mask==all) return 1;
    if(dp[ind][mask]!=-1) return dp[ind][mask];
    ll ans=0;
    for(ll i=0;i<10;i++){
        if((all & 1<<i) && !(mask & 1<<i)){
            auto it=upper_bound(all(v[i]),ind);
            if(it!=v[i].end())
                ans+=solve(v,*it,mask|1<<i);
        }
    }
    return dp[ind][mask]=ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll t,n,i;
	cin>>t;
	while(t--)
	{
	    string s;
		cin>>s;
		vector<vector<ll> > v(10);
		reset();
		for(i=0;i<s.size();i++){
		    all|=(1<<(s[i]-'0'));
            v[s[i]-'0'].pb(i+1);
		}
		cout<<solve(v,0,0)<<"\n";
	}
	return 0;
}
