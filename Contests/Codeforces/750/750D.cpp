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
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

ll n,dist[31];
ll dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};
bool m[301][301][31][8];
bool vis[301][301];

void solve(ll x, ll y, ll dir, ll depth){
    if(depth==n) return;
    if(m[x][y][depth][dir]) return;
    m[x][y][depth][dir]=true;
    for(ll i=0;i<dist[depth];i++){
        x+=dx[dir];
        y+=dy[dir];
        vis[x][y]=true;
    }
    solve(x,y,(dir+1)%8,depth+1);
    solve(x,y,(dir+7)%8,depth+1);
}

int main()
{
	FastIO
	ll i,ans=0;
	cin>>n;
	for(i=0;i<n;i++) cin>>dist[i];
	solve(155,155,2,0);
	for(i=0;i<301;i++)
        for(ll j=0;j<301;j++)
        if(vis[i][j]) ans++;
    cout<<ans;
	return 0;
}
