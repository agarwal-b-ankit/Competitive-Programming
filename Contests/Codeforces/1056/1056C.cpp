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
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n,m,t,i,a,b,val=0;
	cin>>n>>m;
	vector<ll> hero(2*n+1);
	set<pair<ll,ll>> s,s1;
    set<pair<ll,ll> >::iterator it;
	map<ll,ll> pos;
	for(i=1;i<=2*n;i++){
        cin>>hero[i];
        s.insert(mp(hero[i],i));
	}
	for(i=0;i<m;i++){
        cin>>a>>b;
        pos[a]=b;
        pos[b]=a;
        s1.insert(mp(hero[a],a));
        s1.insert(mp(hero[b],b));
	}
    cin>>t;
    for(i=0;i<2*n;i++){
        if((i%2==0 && t==1) || (i%2==1 && t==2)){
            if(s1.size()%2==1){
                cout<<pos[val]<<endl;
                s.erase(mp(hero[pos[val]],pos[val]));
                s1.erase(mp(hero[pos[val]],pos[val]));
            } else{
                if(!s1.empty()) it=s1.end();
                else it=s.end();
                it--;
                cout<<it->second<<endl;
                s.erase(mp(hero[it->second],it->second));
                s1.erase(mp(hero[it->second],it->second));
                pos[it->second]=0;
            }
        } else{
            cin>>val;
            s.erase(mp(hero[val],val));
            s1.erase(mp(hero[val],val));
        }
    }
    cout.flush();
	return 0;
}
