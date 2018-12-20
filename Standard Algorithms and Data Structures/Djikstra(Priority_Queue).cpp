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

void djikstra(ll src){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push(mp(0,src));
    dist[src]=0;
    while(!pq.empty()){
        ll u=pq.top().ss;
        pq.pop();
        for(auto &v:adj[u]){
            if(dist[u]+v.ss<dist[v.ff]){
                dist[v.ff]=dist[u]+v.ss;
                pq.push(mp(dist[v.ff],v.ff));
            }
        }
    }
}

void init(){
    for(ll i=0;i<MAXN;i++)
        dist[i]=INF;
}

void addEdge(ll u, ll v, ll w){
    adj[u].pb(mp(v,w));
    adj[v].pb(mp(u,w));
}

int main()
{
	//FastIO
	init();
	ll t,n,i;
	addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
    djikstra(0);
    for(i=0;i<=8;i++) cout<<"distance from 0 to "<<i<<" is "<<dist[i]<<endl;
	return 0;
}
