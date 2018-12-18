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

bool lies(ll c1, ll c, ll k){
    if(c1>=c-k && c1<=c+k) return true;
    else return false;
}

int main()
{
	//FastIO
	ll q,k,n,i,j,b,d,c=0,ans=0,temp,left=200005,right=200005;
	cin>>q>>k;
	vector<pair<ll,ll> > v(400010);
	while(q--)
	{
	    cin>>b>>c;
	    c^=ans;
	    if(b==1){
	        cin>>d;
	        v[--left]=mp(c,d);
	    } else if(b==2){
	        cin>>d;
	        v[right++]=mp(c,d);
	    } else{
	        ans=0;temp=0;
	        for(i=left;i<right;i++){
	            if(lies(v[i].ff,c,k)) temp+=v[i].ss;
	            ans=max(ans,temp);
	            if(temp<0) temp=0;
	        }
	        cout<<ans<<"\n";
	    }
	}
	return 0;
}
