#include <bits/stdc++.h>
using namespace std;
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

int main()
{
	ll t,n,i,flag=0;
	cin>>n;
	vector<int> a(n),b(n),c(n);
	for(i=0;i<n-1;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++)
        cin>>b[i];
    for(ll s=0;s<4;s++){
        c[0]=s;
        for(i=0;i<n-1;i++){
            c[i+1]=b[i]+a[i]-c[i];
            if((c[i+1]|c[i])==a[i] && (c[i+1]&c[i])==b[i])
                continue;
            else break;
        }
        if(i==n-1){
            flag=1;
            cout<<"YES"<<endl;
            for(i=0;i<n;i++) cout<<c[i]<<" ";
            break;
        }
    }
    if(flag==0) cout<<"NO";
	return 0;
}
