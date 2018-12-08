#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

bool comp1(pair<ll,ll> p1, pair<ll,ll> p2)
{
    return p1.ff<p2.ff;
}

ll interval(vector<pair<ll,ll> > &v, ll left, ll right)
{
    if(v.size()==0)
        return -1;
    ll i,cnt=0,siz=0;
    sort(v.begin(),v.end(),comp1);
    vector<ll> rig(v.size());
    rig[0]=v[0].ss;
    for(i=1;i<v.size();i++)
        rig[i]=max(rig[i-1],v[i].ss);
    while(left<=right)
    {
        ll pos=upper_bound(v.begin(),v.end(),mp(left,INF),comp1)-v.begin();
        if(pos==0 || rig[pos-1]<left)
            return -1;
        cnt++;
        left=rig[pos-1]+1;
    }
    return cnt;
}

int main()
{
	ll t,n,k,m,i,hx,hy,tx,ty;
	cin>>t;
	while(t--)
    {
        cin>>n>>k>>m;
        vector<pair<ll,ll> > hor,ver;
        ll left=(n-k)/2+1;
        ll right=left+k-1;
        while(m--)
        {
            scanf("%lld%lld%lld%lld",&hx,&hy,&tx,&ty);
            if(hx==tx)
            {
                ver.pb(mp(min(hy,ty),max(hy,ty)));
                hor.pb(mp(hx,hx));
            }
            else
            {
                hor.pb(mp(min(hx,tx),max(hx,tx)));
                ver.pb(mp(hy,hy));
            }
        }
        ll h=interval(hor,left,right),v=interval(ver,left,right);
        // cout<<endl<<h<<" "<<v<<endl;
        if(h==-1 || v==-1)
            cout<<-1<<endl;
        else cout<<(h+v)<<endl;
    }
	return 0;
}
