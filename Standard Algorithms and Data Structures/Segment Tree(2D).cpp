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
const ll MAXN=1010;

ll tree[4*MAXN][4*MAXN],a[MAXN][MAXN];

void buildY(ll nodex, ll sx, ll ex, ll nodey, ll sy, ll ey){
    if(sy==ey){
        if(sx==ex) tree[nodex][nodey]=a[sx][sy];
        else tree[nodex][nodey]=tree[2*nodex][nodey]+tree[2*nodex+1][nodey];
        return;
    }
    ll mid=(sy+ey)/2;
    buildY(nodex,sx,ex,2*nodey,sy,mid);
    buildY(nodex,sx,ex,2*nodey+1,mid+1,ey);
    tree[nodex][nodey]=tree[nodex][2*nodey]+tree[nodex][2*nodey+1];
}

void buildX(ll nodex, ll sx, ll ex, ll sy, ll ey){
    if(sx!=ex){
        ll mid=(sx+ex)/2;
        buildX(2*nodex,sx,mid,sy,ey);
        buildX(2*nodex+1,mid+1,ex,sy,ey);
    }
    buildY(nodex,sx,ex,1,sy,ey);
}

void updateY(ll nodex, ll sx, ll ex, ll nodey, ll sy, ll ey, ll x, ll y, ll val){
    if(sy==ey){
        if(sx==ex) tree[nodex][nodey]=val;
        else tree[nodex][nodey]=tree[2*nodex][nodey]+tree[2*nodex+1][nodey];
        return;
    }
    ll mid=(sy+ey)/2;
    if(y<=mid) updateY(nodex,sx,ex,2*nodey,sy,mid,x,y,val);
    else updateY(nodex,sx,ex,2*nodey+1,mid+1,ey,x,y,val);
    tree[nodex][nodey]=tree[nodex][2*nodey]+tree[nodex][2*nodey+1];
}

void updateX(ll nodex, ll sx, ll ex, ll sy, ll ey, ll x, ll y, ll val){
    if(sx!=ex){
        ll mid=(sx+ex)/2;
        if(x<=mid) updateX(2*nodex,sx,mid,sy,ey,x,y,val);
        else updateX(2*nodex+1,mid+1,ex,sy,ey,x,y,val);
    }
    updateY(nodex,sx,ex,1,sy,ey,x,y,val);
}


ll queryY(ll nodex, ll nodey, ll sy, ll ey, ll ly, ll ry){
    if(ry<sy || ly>ey) return 0;
    if(sy>=ly && ey<=ry) return tree[nodex][nodey];
    ll mid=(sy+ey)/2;
    ll p1=queryY(nodex,2*nodey,sy,mid,ly,ry),p2=queryY(nodex,2*nodey+1,mid+1,ey,ly,ry);
    return p1+p2;
}

ll queryX(ll nodex, ll sx, ll ex, ll sy, ll ey, ll lx, ll ly, ll rx, ll ry){
    if(rx<sx || lx>ex) return 0;
    if(sx>=lx && ex<=rx) return queryY(nodex,1,sy,ey,ly,ry);
    ll mid=(sx+ex)/2;
    ll p1=queryX(2*nodex,sx,mid,sy,ey,lx,ly,rx,ry),p2=queryX(2*nodex+1,mid+1,ex,sy,ey,lx,ly,rx,ry);
    return p1+p2;
}

int main()
{
	//FastIO
	// 1 2 3 4
	// 5 6 7 8
	// 1 7 5 9
	// 3 0 6 2
	ll n,m,i,j,lx=0,ly=0,rx,ry;
	cin>>n>>m;
	rx=n-1,ry=m-1;
	for(i=lx;i<=rx;i++)
	    for(j=ly;j<=ry;j++)
	        cin>>a[i][j];
	buildX(1,lx,rx,ly,ry);
	cout<<queryX(1,0,3,0,3,0,0,3,3)<<endl;
	updateX(1,0,3,0,3,1,2,8);
	updateX(1,0,3,0,3,2,3,8);
	updateX(1,0,3,0,3,3,3,8);
	cout<<queryX(1,0,3,0,3,0,0,3,3)<<endl;
	return 0;
}
