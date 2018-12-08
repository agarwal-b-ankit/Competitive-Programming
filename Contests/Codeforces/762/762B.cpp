#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

int main()
{
	ll a,b,c,m,i,j,co,tot=0,cnt=0;
	string type;
	cin>>a>>b>>c>>m;
	vector<ll> ps,us;
	for(i=0;i<m;i++)
    {
        cin>>co>>type;
        if(type.compare("USB")==0)
            us.pb(co);
        else ps.pb(co);
    }
    sort(all(ps));
    sort(all(us));
    for(i=0;i<us.size() && a>0;i++)
    {
        tot+=us[i];
        a--;
        cnt++;
    }
    for(j=0;j<ps.size() && b>0;j++)
    {
        tot+=ps[j];
        b--;
        cnt++;
    }
    for(;c>0 && (i<us.size() || j<ps.size());)
    {
        if(i<us.size() && j<ps.size())
        {
            if(us[i]<ps[j])
            {
                tot+=us[i];
                i++;
            }
            else
            {
                tot+=ps[j];
                j++;
            }
        }
        else if(j<ps.size())
        {
            tot+=ps[j];
            j++;
        }
        else
        {
            tot+=us[i];
            i++;
        }
        c--;
        cnt++;
    }
    cout<<cnt<<" "<<tot;
	return 0;
}
