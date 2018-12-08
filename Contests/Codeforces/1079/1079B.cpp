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
	string s;
	cin>>s;
	ll siz=s.size();
    ll row=siz/20;
    if(siz%20!=0) row++;
    ll col=siz/row;
    if(siz%row!=0) col++;
    cout<<row<<" "<<col<<endl;
    ll extrac=siz%row;
    ll li=-1;
    for(ll i=0;i<row;i++){
        ll ncp=siz/row;
        if(extrac>0){
            ncp++;
            extrac--;
            cout<<s.substr(li+1,ncp);
        } else{
        cout<<s.substr(li+1,ncp);
        if(siz%row!=0) cout<<"*";
        }
        li+=ncp;
        cout<<endl;
    }
	return 0;
}
