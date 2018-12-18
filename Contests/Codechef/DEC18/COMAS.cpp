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

map<pair<ll,ll>, map<ll,ll> > m;
map<pair<ll,ll>,ll> mcnt;

void printQ(set<ll> &s){
    cout<<"? ";
    for(auto it:s) cout<<it<<" ";
    cout<<endl<<flush;
}

void askQ(set<ll> &s, bool finalFlag){
    ll a,b;
    printQ(s);
    cin>>a>>b;
    if(!finalFlag){
        s.erase(a);
        s.erase(b);
    } else{
        pair<ll,ll> key = mp(min(a,b),max(a,b));
        map<ll,ll> m1;
        if(present(m,key)){
           m1=m[key];
        }
        for(auto it:s) if(it!=a && it!=b) m1[it]++;
        m[key]=m1;
        mcnt[key]++;
    }
}

ll solve(){
    ll n,i,j,a,b;
    cin>>n;
    set<ll> s;
    for(i=1;i<=n-3;i++){
        s.insert(i);
        if(s.size()==5)
            askQ(s,false);
    }
    if(s.size()==4){
        s.insert(i++);
        printQ(s);
        cin>>a>>b;
        s.erase(a);
    }
    for(;i<=n;i++) s.insert(i);
    vector<ll> v(all(s));
    for(auto val1:v){
        set<ll> s1;
        for(auto val2:v){
            if(val1!=val2)
                s1.insert(val2);
        }
        askQ(s1,true);
    }
    for(auto it:mcnt){
        if(it.ss==3){
            map<ll,ll> temp=m[it.ff];
            for(auto it1:temp){
                if(it1.ss==3){
                    return it1.ff;
                }
            }
        }
    }
}

int main()
{
	//FastIO
	ll t;
	cin>>t;
	while(t--)
	{
	    m.clear();
	    mcnt.clear();
	    ll ans=solve();
	    cout<<"! "<<ans<<endl<<flush;
	}
	return 0;
}
