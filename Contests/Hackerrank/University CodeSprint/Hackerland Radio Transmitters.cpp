#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
	LL n,k,i;
	cin>>n>>k;
	LL a[n];
	for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    LL prev=a[0],pre,cnt=1;
    for(i=0;i<n;i++)
    {
        if(a[i]<=prev+k)
            {
                pre=a[i];
                continue;
            }
        while(a[i]<=pre+k)
            i++;
        if(i==n)
            break;
        pre=prev=a[i];
        i--;
        cnt++;
    }
    cout<<cnt;
	return 0;
}
