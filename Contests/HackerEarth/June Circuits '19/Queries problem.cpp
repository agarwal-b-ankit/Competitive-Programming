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
 
double a[MAXN];
 
double getDiff(double csum, double tsum){
    return abs(2*csum-tsum);
}

int main()
{
	//FastIO
	ll n,m,i,x=1;
	cin>>n>>m;
	double tsum=0,csum=0,msum=INF,lsum=0;
	for(i=1;i<=n;i++){
	    cin>>a[i];
	    a[i]=log(a[i]);
	    tsum+=a[i];
	}
	for(i=1;i<=n;i++){
	    lsum+=a[i];
	    if(getDiff(lsum,tsum)<msum){
	        msum=getDiff(lsum,tsum);
	        csum=lsum;
	        x=i;
	    }
	}
	while(m--){
	    ll type,pos,val;
		cin>>type;
		if(type==1){
		    cin>>pos>>val;
	        double diff=log(val);
	        a[pos]+=diff;
	        tsum+=diff;
	        if(pos<=x){
	            csum+=diff;
	            msum=getDiff(csum,tsum);
	            while(x>1){
	                if(getDiff(csum-a[x],tsum)<=msum){
	                    msum=getDiff(csum-a[x],tsum);
	                    csum-=a[x];
	                    x--;
	                } else break;
	            }
	        } else{
	            msum=getDiff(csum,tsum);
	            while(x<n){
	                if(getDiff(csum+a[x+1],tsum)<msum){
	                    msum=getDiff(csum+a[x+1],tsum);
	                    csum+=a[x+1];
	                    x++;
	                } else break;
	            }
	        }
		} else
		    cout<<x<<"\n";
	}
	return 0;
}