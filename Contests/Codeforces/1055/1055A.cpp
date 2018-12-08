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

bool solve(vector<int> &v1, vector<int> &v2, int s){
    if(v1[0]==0) return false;
    if(v1[s-1]==1) return true;
    if(v2[s-1]==1){
        for(int i=s;i<v1.size();i++)
            if(v1[i]==1 && v2[i]==1)
                return true;
    }
    return false;
}

int main()
{
	ll n,s,i;
	cin>>n>>s;
	vector<int> v1(n),v2(n);
	for(i=0;i<n;i++)
        cin>>v1[i];
	for(i=0;i<n;i++)
        cin>>v2[i];
    if(solve(v1,v2,s)) cout<<"YES";
    else cout<<"NO";
	return 0;
}
