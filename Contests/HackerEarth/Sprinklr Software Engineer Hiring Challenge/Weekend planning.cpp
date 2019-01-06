#include <bits/stdc++.h>
using namespace std;
// uncomment for using ordered set provided by GNU++ library
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define present(m,v) (m.find(v)!=m.end())
#define mod 1000000007
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
ll INF=numeric_limits<ll>::max();
const ll MAXN=100010;

ll dist[MAXN];
vector<pair<ll,ll>> adj[MAXN];
multiset<ll> heap[MAXN];

void djikstra(ll src, ll k){
    for(ll i=0;i<MAXN;i++)
        dist[i]=INF;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push(mp(0,src));
    dist[src]=0;
    while(!pq.empty()){
        ll u=pq.top().ss;
        pq.pop();
        for(auto &v:adj[u]){
            ll tsum=0,csum=0;
            multiset<ll> temp;
            for(auto e:heap[v.ff]) csum+=e;
            /*csum=dist[v.ff]-csum;*/
            if(dist[u]+v.ss<dist[v.ff]){
                dist[v.ff]=dist[u]+v.ss;
                pq.push(mp(dist[v.ff],v.ff));
            }
            for(auto e:heap[u]){
                temp.insert(e);
                tsum+=e;
            }
            temp.insert(v.ss);
            tsum+=v.ss;
            if(temp.size()>k){
                tsum-=(*temp.begin());
                temp.erase(temp.begin());
            }
            /*tsum=dist[v.ff]-tsum;*/
            if(tsum>csum || (tsum==csum && temp.size()<heap[v.ff].size()))
                heap[v.ff]=temp;
        }
    }
}

void addEdge(ll u, ll v, ll w){
    adj[u].pb(mp(v,w));
    adj[v].pb(mp(u,w));
}

multiset<ll> mt;

void bfs(ll src, ll k){
    queue<ll> q;
    q.push(src);
    vector<bool> vis(MAXN,false);
    ll cnt=0;
    while(!q.empty()){
        if(cnt>k) return;
        ll siz=q.size();
        while(siz--){
            ll val=q.front();q.pop();
            vis[val]=true;
            dist[val]=-1;
            if(!vis[val]) q.push(val);
        }
        cnt++;
    }
}

int main()
{
	FastIO
	ll n,m,k,u,v,c,i;
	cin>>n>>m>>k;
	for(i=0;i<m;i++){
        cin>>u>>v>>c;
        addEdge(u,v,c);
	}
	djikstra(1,k);
	bfs(1,k);
	for(i=1;i<=n;i++){
        ll sum=0;
        for(auto e:heap[i]) sum+=e;
        if(k>=6 || dist[i]==-1 || dist[i]-sum<=0) cout<<"0 ";
        else cout<<dist[i]-sum<<" ";
	}
	return 0;
}
