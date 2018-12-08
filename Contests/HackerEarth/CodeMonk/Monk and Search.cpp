#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
	int n,p,pos,t;
	cin>>n;
	vector<LL> a(n,0);
	for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    int q;
    cin>>q;
    while(q--)
    {
        cin>>p>>pos;
        if(p==0)
        {
            int val=lower_bound(a.begin(),a.end(),pos)-a.begin();
            cout<<n-val<<endl;
        }
        else
        {
            int val=upper_bound(a.begin(),a.end(),pos)-a.begin();
            cout<<n-val<<endl;
        }
    }
	return 0;
}
