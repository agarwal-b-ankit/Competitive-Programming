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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

int main()
{
	ll t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll a[n][m];
		ll val=0;
		vector<pair<ll,ll> > ele,tmp;
		vector<vector<bool> > vis(n,vector<bool>(m,false));
		for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]>val)
                {
                    val=a[i][j];
                    ele=tmp;
                    ele.pb(mp(i,j));
                }
                else if(a[i][j]==val)
                    ele.pb(mp(i,j));
            }
        }
        queue<pair<ll,ll> > q;
        for(i=0;i<ele.size();i++)
        {
            q.push(ele[i]);
            vis[ele[i].ff][ele[i].ss]=true;
        }
        ll cnt=0;
        while(!q.empty())
        {
            ll siz=q.size();
            while(siz--)
            {
                pair<ll,ll> p=q.front();
                q.pop();
                if(p.ff>0 && p.ss>0 && !vis[p.ff-1][p.ss-1])
                {
                    vis[p.ff-1][p.ss-1]=true;
                    q.push(mp(p.ff-1,p.ss-1));
                }
                if(p.ff>0 && !vis[p.ff-1][p.ss])
                {
                    vis[p.ff-1][p.ss]=true;
                    q.push(mp(p.ff-1,p.ss));
                }
                if(p.ff>0 && p.ss<m-1 && !vis[p.ff-1][p.ss+1])
                {
                    vis[p.ff-1][p.ss+1]=true;
                    q.push(mp(p.ff-1,p.ss+1));
                }
                if(p.ss>0 && !vis[p.ff][p.ss-1])
                {
                    vis[p.ff][p.ss-1]=true;
                    q.push(mp(p.ff,p.ss-1));
                }
                if(p.ss<m-1 && !vis[p.ff][p.ss+1])
                {
                    vis[p.ff][p.ss+1]=true;
                    q.push(mp(p.ff,p.ss+1));
                }
                if(p.ff<n-1 && p.ss>0 && !vis[p.ff+1][p.ss-1])
                {
                    vis[p.ff+1][p.ss-1]=true;
                    q.push(mp(p.ff+1,p.ss-1));
                }
                if(p.ff<n-1 && !vis[p.ff+1][p.ss])
                {
                    vis[p.ff+1][p.ss]=true;
                    q.push(mp(p.ff+1,p.ss));
                }
                if(p.ff<n-1 && p.ss<m-1 && !vis[p.ff+1][p.ss+1])
                {
                    vis[p.ff+1][p.ss+1]=true;
                    q.push(mp(p.ff+1,p.ss+1));
                }
            }
            if(!q.empty())
                cnt++;
        }
        cout<<cnt<<endl;
	}
	return 0;
}
