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
    ll t,n,i,j;
    cin>>n;
    string s;
    map<string,int> m,m1;
    for(i=0;i<n;i++){
        cin>>s;
        m1[s]++;
        for(j=1;j<=s.length();j++){
            if(!present(m,s.substr(0,j))){
                cout<<s.substr(0,j)<<endl;
                break;
            }
            m[s.substr(0,j)]++;
        }
        if(j>s.length()){
            if(m1[s]==1)
            cout<<s<<endl;
            else
            cout<<s<<" "<<m1[s]<<endl;
        }
        for(j=1;j<=s.length();j++){
            if(!present(m,s.substr(0,j))){
                m[s.substr(0,j)]++;
            }
        }
    }
    return 0;
}
