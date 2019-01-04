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

int main()
{
	//FastIO
	ll t,n,i;
	cin>>n;
	vector<pair<char,ll>> v(n);
	for(i=0;i<n;i++) cin>>v[i].ss;
	for(i=0;i<n;i++) cin>>v[i].ff;
	ll time=0,stamina=0,grassL=0;
	bool hadWater=false;
	for(auto p:v){
        if(p.ff=='G'){
            time+=p.ss*5;
            stamina+=p.ss;
            grassL+=2*p.ss;
        } else if(p.ff=='W'){
            hadWater=true;
            stamina+=p.ss;
            time+=p.ss*3;
        } else{
            time+=p.ss;
            stamina-=p.ss;
            if(stamina<0){
                // swim or walk in-place
                if(hadWater) time-=3*stamina;
                else time-=5*stamina;
                stamina=0;
            }
        }
        grassL=min(grassL,stamina);
	}
	if(stamina>0){
        // convert walking into flying
        time-=2*grassL;
        stamina-=grassL;
	}
	if(stamina>0){
	    // convert swimming into flying
        time-=stamina;
	}
	cout<<time;
	return 0;
}
