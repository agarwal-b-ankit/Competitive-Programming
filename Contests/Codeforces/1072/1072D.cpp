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
	ll n,k,i,j;
	cin>>n>>k;
    char v[n][n];
	for(i=0;i<n;i++){
        scanf("%s",v[i]);
	}
	map<pair<ll,ll>,ll > m;
	map<pair<ll,ll>,ll >::iterator it;
	m[mp(0,0)]=k;
	while(!m.empty()){
        char sm='z';
        ll maxk=-1;
        vector<pair<pair<ll,ll>,ll> > temp;
        for(it = m.begin(); it != m.end(); ++it ){
            temp.pb(mp(mp((it->first).ff,(it->first).ss),it->second));
        }
        m.clear();
        for(pair<pair<ll,ll>,ll> pr : temp){
                pair<ll,ll> p=pr.ff;
            if(v[p.ff][p.ss]<sm)
                sm=v[p.ff][p.ss];
            if(pr.ss>maxk)
                maxk=pr.ss;
        }
        for(pair<pair<ll,ll>,ll> pr : temp){
             pair<ll,ll> p=pr.ff;
            if(v[p.ff][p.ss] == 'a'){
                if(p.ss+1<n) m[mp(p.ff,p.ss+1)]=max(m[mp(p.ff,p.ss+1)],pr.ss);
                if(p.ff+1<n) m[mp(p.ff+1,p.ss)]=max(m[mp(p.ff+1,p.ss)],pr.ss);
                }
            else if(pr.ss>0){
                if(p.ss+1<n) m[mp(p.ff,p.ss+1)]=max(m[mp(p.ff,p.ss+1)],pr.ss-1);
                if(p.ff+1<n) m[mp(p.ff+1,p.ss)]=max(m[mp(p.ff+1,p.ss)],pr.ss-1);
            } else if(v[p.ff][p.ss] == sm && maxk<=0 ){
                if(p.ss+1<n) m[mp(p.ff,p.ss+1)]=max(m[mp(p.ff,p.ss+1)],pr.ss);
                if(p.ff+1<n) m[mp(p.ff+1,p.ss)]=max(m[mp(p.ff+1,p.ss)],pr.ss);
            }
        }
        if(maxk>0) sm='a';
        printf("%c",sm);
	}

	return 0;
}
