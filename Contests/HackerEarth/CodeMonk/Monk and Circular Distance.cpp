#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
	int n,i;
	LL x,y;
	cin>>n;
	vector<long double> a;
	for(i=0;i<n;i++)
    {
        cin>>x>>y;
        a.push_back(sqrt(x*x+y*y));
    }
    sort(a.begin(),a.end());
    int q;
    long double r;
    cin>>q;
    while(q--)
    {
        cin>>r;
        int val=upper_bound(a.begin(),a.end(),r)-a.begin();
        cout<<val<<endl;
    }
	return 0;
}
