#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll q,n,c,k,val=0,ty,i,ind;
	cin>>n;
	vector<ordered_set> col(n+1);
	ordered_set ms;
	while(n--){
        cin>>c;
        col[c].insert(val++);
	}
	cin>>q;
	while(q--)
	{
		cin>>ty>>c;
		if(ty==1) {
            col[c].insert(val++);
		} else {
		    cin>>k;
		    ind=col[c].size()-k;
            if(ind>=0){
                ll temp = *(col[c].find_by_order(ind));
                col[c].erase(temp);
                ms.insert(temp);
                cout<<val-temp-((ll)ms.size()-ms.order_of_key(temp));
            } else cout<<"-1";
            cout<<"\n";
		}
	}
	return 0;
}
