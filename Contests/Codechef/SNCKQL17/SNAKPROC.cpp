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
	ll r,i,l;
	cin>>r;
	while(r--)
	{
	    cin>>l;
	    string s;
	    cin>>s;
	    bool snake=false;
	    for(i=0;i<s.size();i++)
        {
            if(s[i]=='.')
                continue;
            if(!snake && s[i]=='H')
                snake=true;
            else if(snake && s[i]=='T')
                snake=false;
            else break;
        }
	    if(i!=s.size() || snake)
            cout<<"Invalid";
        else cout<<"Valid";
        cout<<endl;
	}
	return 0;
}
