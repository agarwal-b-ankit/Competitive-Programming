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

vector<ll> vp;

ll leaf(vector<vector<ll>> &v, ll src,vector<bool> &vis){
    vis[src]=true;
    ll nl=0;
    for(ll i: v[src]){
        if(!vis[i])
        nl+=leaf(v,i,vis);
    }
    if(nl==0){
        nl=1;
    }
    vp.pb(nl);
    return nl;
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n,i,val;
	cin>>n;
	vector<vector<ll> > v(n);
	for(i=1;i<n;i++){
        cin>>val;
        v[i].pb(val-1);
        v[val-1].pb(i);
	}
	vector<bool> vis(n,false);
	leaf(v,0,vis);
	sort(all(vp));
	for(ll val:vp) cout<<val<<" ";
	return 0;
}
