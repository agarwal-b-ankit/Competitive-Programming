#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18

bool stable(vector<string> &s)
{
    ll i,j;
    for(i=0;i<s.size()-1;i++)
    {
        for(j=0;j<s[i].size();j++)
        {
            if((s[i][j]=='B' || s[i][j]=='W') && s[i+1][j]=='A')
                return false;
            else if(s[i][j]=='B' && s[i+1][j]=='W')
                return false;
        }
    }
    for(i=0;i<s.size();i++)
    {
        for(j=0;j<s[i].size()-1;j++)
        {
            if(s[i][j]=='A' && s[i][j+1]=='W')
                return false;
            if(s[i][j]=='W' && s[i][j+1]=='A')
            return false;
        }
    }
    for(i=0;i<s.size();i++)
    {
        if(s[i][0]=='W' || s[i][s[i].size()-1]=='W')
            return false;
    }
    return true;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
    {
        ll n,m,i;
        cin>>n>>m;
        vector<string> s(n,"");
        for(i=0;i<n;i++)
            cin>>s[i];
        if(stable(s))
            cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
	return 0;
}
