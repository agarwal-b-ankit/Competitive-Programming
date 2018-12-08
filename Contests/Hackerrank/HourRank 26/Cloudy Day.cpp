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

ll solve(vector<pair<ll,ll>> &town, ll li, ll ri){
    if(ri<li) return 0;
    ll ub = upper_bound(all(town),mp(ri,(ll)INF))-town.begin();
    ub--;
    ll lb = lower_bound(all(town),mp(li,-1ll))-town.begin();
    lb--;
    return town[ub].ss-town[lb].ss;
}

int main()
{
    //FastIO
    ll t,n,m,i,li=0,ans=0,maxv=0;
    cin>>n;
    vector<pair<ll,ll>> town(n+1);
    vector<pair<ll,pair<ll,ll> > > v;
    town[0]=mp(-1,0);
    for(i=1;i<=n;i++)
        cin>>town[i].ss;
    for(i=1;i<=n;i++)
        cin>>town[i].ff;
    sort(all(town));
    for(i=1;i<=n;i++)
        town[i].ss+=town[i-1].ss;
    cin>>m;
    vector<pair<ll,ll>> cloud(m+1);
    for(i=1;i<=m;i++)
        cin>>cloud[i].ff;
    for(i=1;i<=m;i++)
        cin>>cloud[i].ss;
    for(i=1;i<=m;i++){
        v.pb(mp(max(0ll,cloud[i].ff-cloud[i].ss),mp(0,i)));
        v.pb(mp(cloud[i].ff+cloud[i].ss,mp(1,i)));
    }
    sort(all(v));
    set<ll> s;
    map<ll,ll> ma;
    for(i=0;i<v.size();i++){
        if(v[i].ss.ff==0){
            if(s.size()==1){
                ma[*s.begin()]+=solve(town,li,v[i].ff-1);
            } else if(s.size()==0) ans+=solve(town,li,v[i].ff-1);
            li=v[i].ff;
            s.insert(v[i].ss.ss);
        } else{
            if(s.size()==1){
                ma[*s.begin()]+=solve(town,li,v[i].ff);
            }
            li=v[i].ff+1;
            s.erase(v[i].ss.ss);
        }
    }
    ans+=solve(town,li,town[town.size()-1].ff);
    for(auto val:ma) maxv=max(maxv,val.second);
    ans+=maxv;
    cout<<ans;
    return 0;
}
