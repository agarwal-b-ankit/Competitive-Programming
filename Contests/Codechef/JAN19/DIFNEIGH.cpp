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
	FastIO
	ll t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<vector<ll>> a(n,vector<ll>(m,0));
		ll val=2,ma=1;
		if(n==1){
            for(j=0;j<m;j++){
                if(j%2==0) val=3^val;
                a[0][j]=val;
                ma=max(ma,a[0][j]);
            }
        } else if(m==1){
            for(i=0;i<n;i++){
                if(i%2==0) val=3^val;
                a[i][0]=val;
                ma=max(ma,a[i][0]);
            }
        } else if(n==2){
            for(j=0;j<m;j++){
                a[0][j]=a[1][j]=j%3+1;
                ma=max(ma,a[0][j]);
            }
        } else if(m==2){
            for(i=0;i<n;i++){
                a[i][0]=a[i][1]=i%3+1;
                ma=max(ma,a[i][0]);
            }
        } else{
            for(j=0;j<m;j++){
                if(j%2==0) val=2-val;
                for(i=0;i<n;i++){
                    a[i][j]=(i+val)%4+1;
                    ma=max(ma,a[i][j]);
                }
            }
        }
        cout<<ma<<"\n";
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
	}
	return 0;
}
