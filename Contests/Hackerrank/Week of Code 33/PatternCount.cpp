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
	ll q,n,i;
	cin>>q;
	string s;
	while(q--)
    {
        cin>>s;
        string s1="";
        s1+=s[0];
        for(i=1;i<s.size();i++)
        {
            if(s[i]=='0' && s[i]==s[i-1])
                continue;
            s1+=s[i];
        }
        ll ind=0,cnt=0;
        while(s1.find("101",ind)!=string::npos)
        {
            cnt++;
            ind=2+s1.find("101",ind);
        }
        cout<<cnt<<endl;
    }
	return 0;
}
