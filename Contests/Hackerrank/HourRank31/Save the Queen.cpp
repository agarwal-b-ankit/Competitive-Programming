#include <bits/stdc++.h>
using namespace std;
// uncomment for using ordered set provided by GNU++ library
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pref_trie trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>
*/

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
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
    //FastIO
    //cout << std::fixed;cout << std::setprecision(2);
    ll n,k,i;
    double ans=0;
    cout << std::fixed;
    cout << std::setprecision(6);
    cin>>n>>k;
    vector<ll> v(k);
    for(i=0;i<k;i++)
        cin>>v[i];
    sort(all(v));
    if(n>k)
        ans=0;
    else if(n==k)
        ans=v[0];
    else{
        ans=v[k-n];
        ll sum=0,diff=0,pos=1;
        for(i=0;i<k-n;i++){
            sum+=v[i];
        }
        for(i=k-n+1;i<k;i++){
            diff=v[i]-v[i-1];
            if(sum>=diff*pos){
                sum-=diff*pos;
                pos++;
                ans=v[i];
            } else break;
        }
        if(sum>0){
            ans+=((double)sum)/pos;
        }
    }
    cout<<ans;
    return 0;
}
