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
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t,n,i;
	cin>>t;
	while(t--){
        cin>>n;
        vector<pair<ll,ll>> v(n);
        ll na=0,nb=0,tna=0,tnb=0,ans=0;
        for(i=0;i<n;i++){
            cin>>v[i].ff;
            char c;
            cin>>c;
            if(c=='A'){
                v[i].ss=0;
                na+=v[i].ff;
            }
            else {
                v[i].ss=1;
                nb+=v[i].ff;
            }
        }
        if(na==0) cout<<nb<<endl;
        else if(nb==0) cout<<na<<endl;
        else{
            ll gcd=__gcd(na,nb);
            na/=gcd;
            nb/=gcd;
            for(pair<ll,ll> p:v){
                if(p.ss==0){
                    if(tnb>0){
                        ll val=(na*tnb)/nb-tna;
                        if(val>0 && val<=p.ff && (tna+val)*nb==na*tnb) {
                            ans++;
                            tna=p.ff-val;
                            tnb=0;
                        } else tna+=p.ff;
                    } else tna+=p.ff;
                } else {
                    if(tna>0){
                        ll val=(nb*tna)/na-tnb;
                        if(val>0 && val<=p.ff && tna*nb==na*(tnb+val)) {
                            ans++;
                            tna=0;
                            tnb=p.ff-val;
                        } else tnb+=p.ff;
                    } else tnb+=p.ff;
                }
            }
            cout<<ans<<endl;
        }
	}
	return 0;
}
