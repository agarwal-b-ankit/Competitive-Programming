#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18

int main()
{
	ll n,d,td=0;
	string s;
	cin>>n;
	while(n--)
    {
        cin>>d>>s;
        if(s=="North")
            td-=d;
        else if(s=="South")
            td+=d;
        if(td<0 || td>20000)
            break;
        if(td==0 || td==20000)
            if(s=="East" || s=="West")
            {
                td=-1;
                break;
            }
    }
    if(td==0)
        cout<<"YES";
    else
        cout<<"NO";
	return 0;
}
