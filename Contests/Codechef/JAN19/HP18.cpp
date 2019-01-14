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
	ll t,n,a,b,val,i,a1,b1,c;
	cin>>t;
	while(t--){
        cin>>n>>a>>b;
        a1=0,b1=0,c=0;
        for(i=0;i<n;i++){
            cin>>val;
            if(val%a==0 && val%b==0) c++;
            else if(val%a==0) a1++;
            else if(val%b==0) b1++;
        }
        if(c>0) c=1;
        if(a1+c>b1) cout<<"BOB\n";
        else cout<<"ALICE\n";
	}
	return 0;
}
