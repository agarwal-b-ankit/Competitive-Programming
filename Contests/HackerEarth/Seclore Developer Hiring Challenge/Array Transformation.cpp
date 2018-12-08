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

ll solve(vector<vector<pair<ll,ll> > > &v, ll src, ll dest, ll n){
    if(src==dest) return 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> dist(n+1,INF);
    dist[src]=0;
    pq.push(mp(0,src));
    while(!pq.empty()){
        pair<ll,ll> ip = pq.top();
        pq.pop();
        for(pair<ll,ll> vp: v[ip.ss]){
            if(dist[vp.ff]>dist[ip.ss]+vp.ss){
                dist[vp.ff]=dist[ip.ss]+vp.ss;
                pq.push(mp(dist[vp.ff],vp.ff));
            }
        }
    }
    return dist[dest];
}

int main()
{
	ll n,m,x,y,w,i,ans=0;
	cin>>n;
	vector<ll> va(n),vb(n);
	for(i=0;i<n;i++) cin>>va[i];
	for(i=0;i<n;i++) cin>>vb[i];
	cin>>m;
	vector<vector<pair<ll,ll> > > v(n+1);
	while(m--){
        cin>>x>>y>>w;
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
	}
	for(i=0;i<n;i++){
	    if(va[i]==vb[i]) continue;
	    ll temp=solve(v,va[i],vb[i],n);
	    if(temp==INF){
            cout<<"-1";
            return 0;
	    } else ans+=temp;
	}
	cout<<ans;
	return 0;
}
