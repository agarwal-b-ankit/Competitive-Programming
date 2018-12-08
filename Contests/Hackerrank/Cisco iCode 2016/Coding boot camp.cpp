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

ll getExtraSkills(vector<pair<ll,pair<ll,ll> > > &v){
    if(v.size()==0) return 0;
    sort(all(v));
    vector<ll> dp(v.size(),0);
    dp[0]=v[0].ss.ss;
    for(ll i=1;i<v.size();i++)
    {
        dp[i]=dp[i-1];
        ll lb=upper_bound(all(v),mp(v[i].ss.ff,mp(-1ll,0ll)))-v.begin();
        if(lb>0)
            dp[i]=max(dp[i],dp[lb-1]+v[i].ss.ss);
        else dp[i]=max(dp[i],v[i].ss.ss);
    }
    return dp[v.size()-1];
}

ll solve(){
    ll n,i,start,d,k,ans=0;
    char x;
    cin>>n;
    vector<pair<ll,pair<ll,ll> > > comp,extra,extra1;
    for(i=0;i<n;i++){
        cin>>start>>d>>k>>x;
        if(x=='I') comp.pb(mp(start,mp(start+d-1,k)));
        else extra.pb(mp(start,mp(start+d-1,k)));
    }
    comp.pb(mp(1000000010ll,mp(1000000011ll,0)));
    sort(all(comp));
    sort(all(extra));
    ll lcpi=0;
    for(auto cp:comp){
        if(cp.ff<=lcpi) return -1;
        ans+=cp.ss.ss;
        ll lb=upper_bound(all(extra),mp(lcpi+1,mp(-1ll,0ll)))-extra.begin();
        ll ub=upper_bound(all(extra),mp(cp.ff,mp(-1ll,0ll)))-extra.begin();
        if(lb<(ll)extra.size() && lb<ub){
            for(i=lb;i<ub;i++){
                if(extra[i].ss.ff<cp.ff)
                    extra1.pb(mp(extra[i].ss.ff,mp(extra[i].ff,extra[i].ss.ss)));
            }
        }
        lcpi=cp.ss.ff;
    }
    ans+=getExtraSkills(extra1);
    return ans;
}

int main()
{
    FastIO
    ll t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}
