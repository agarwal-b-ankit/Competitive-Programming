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
	ll t,n,i;
	cin>>t;
	while(t--)
	{
	    string s;
		cin>>s;
		vector<bool> dead(s.size(),false);
		ll ns=0,nm=0;
		for(i=0;i<s.size();i++)
        {
            if(s[i]=='s')
            {
                ns++;
                continue;
            }
            nm++;
            if(i>0 && s[i-1]=='s' && !dead[i-1])
                ns--;
            else if(i+1<s.size() && s[i+1]=='s')
            {
                ns--;
                dead[i+1]=true;
            }
        }
        if(ns>nm)
            cout<<"snakes\n";
        else if(ns==nm)
            cout<<"tie\n";
        else cout<<"mongooses\n";
	}
	return 0;
}
