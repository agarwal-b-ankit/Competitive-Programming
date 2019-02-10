#include <bits/stdc++.h>
using namespace std;
// uncomment for using ordered set provided by GNU++ library
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

map<ll,ordered_set> m;

ll getIndex(ll low, ll high, ll pos, ll val, ordered_set &s){
    if(low==high)
        return 1+*s.find_by_order(high);
    ll mid=(low+high)/2;
    ll midval=*s.find_by_order(mid);
    if(val-midval>pos-mid)
        return getIndex(mid+1,high,pos,val,s);
    else return getIndex(low,mid,pos,val,s);
}

int main()
{
	FastIO
	ll type,n,q,i,pos,val;
	cin>>n;
	vector<ll> v(n);
	for(i=0;i<n;i++){
        cin>>v[i];
        m[v[i]].insert(i);
	}
	cin>>q;
	while(q--)
	{
		cin>>type>>pos;
		pos=pos-1;
		if(type==1){
            cin>>val;
            m[v[pos]].erase(pos);
            v[pos]=val;
            m[v[pos]].insert(pos);
		} else{
		    ll posval=m[v[pos]].order_of_key(pos);
		    cout<<getIndex(0,posval, posval, pos, m[v[pos]])<<"\n";
		}
	}
	return 0;
}
