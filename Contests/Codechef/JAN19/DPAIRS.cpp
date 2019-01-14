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
	ll n,m,i=0,j=0,cnt=0;
	cin>>n>>m;
	vector<pair<ll,ll>> a(n),b(m);
	for(i=0;i<n;i++){
        cin>>a[i].ff;
        a[i].ss=i;
	}
	for(i=0;i<m;i++){
        cin>>b[i].ff;
        b[i].ss=i;
	}
	sort(all(a));
	sort(all(b));
	i=0,j=0;
	if(n<=m){
        while(cnt<n+m-1){
            cout<<a[i].ss<<" "<<b[j].ss<<"\n";
            cnt++;
            if(cnt<n+m-1)
                cout<<a[i].ss<<" "<<b[j+1].ss<<"\n";
            cnt++;
            j++;
            if(i<n-1) i++;
            else j++;
        }
	} else{
	    while(cnt<n+m-1){
            cout<<a[i].ss<<" "<<b[j].ss<<"\n";
            cnt++;
            if(cnt<n+m-1)
                cout<<a[i+1].ss<<" "<<b[j].ss<<"\n";
            cnt++;
            i++;
            if(j<m-1) j++;
            else i++;
	    }
	}
	return 0;
}
