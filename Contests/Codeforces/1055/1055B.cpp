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
	ll n,m,l,i,t,p,d,sol=0;
	cin>>n>>m>>l;
    vector<ll> len(n+2,0);
    bool cont=false;
    for(i=1;i<=n;i++) {
        cin>>len[i];
        if(len[i]>l && cont){}
        else if(len[i]>l){
            cont=true;
            sol++;
        } else cont=false;
    }
    while(m--){
        cin>>t;
        if(t==0){
            cout<<sol<<endl;
        } else{
            cin>>p>>d;
            len[p]+=d;
            if(len[p]-d<=l && len[p]>l){
                if(len[p-1]<=l && len[p+1]<=l) sol++;
                else if(len[p-1]>l && len[p+1]>l) sol--;
            }
        }
    }
	return 0;
}
