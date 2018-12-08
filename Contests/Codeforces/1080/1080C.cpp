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
pair<ll,ll> fun(ll x1, ll y1, ll x2, ll y2){
    ll len1=(x2-x1+1)*(y2-y1+1);
    pair<ll,ll> color;
    color.ff=len1/2;
    color.ss=len1/2;
    if(x1%2==0){
        if(y1%2!=0){
            color.ff+=len1%2;
        } else color.ss+=len1%2;
    } else{
        if(y1%2==0){
            color.ff+=len1%2;
        } else color.ss+=len1%2;
    }
    return color;
}


int main()
{
	ll t,n,m,x1,x2,y1,y2,x3,x4,y3,y4,nb1,nw2,nbi=0;
	cin>>t;
	while(t--){
            nbi=0;
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;
        pair<ll,ll> c1=fun(x1,y1,x2,y2);
        pair<ll,ll> c2=fun(x3,y3,x4,y4);
        ll ix1=max(x1,x3),ix2=min(x2,x4);
        ll iy1=max(y1,y3),iy2=min(y2,y4);
        if(ix2>=ix1 && iy2>=iy1){
            pair<ll,ll> ci=fun(ix1,iy1,ix2,iy2);
            nbi=ci.ff;
        }
        pair<ll,ll> to=fun(1,1,n,m);
        ll tw=to.ss+c1.ff-nbi-c2.ss;
        ll tb=to.ff-(c1.ff-nbi)+c2.ss;
        cout<<tw<<" "<<tb<<endl;
	}
	return 0;
}
