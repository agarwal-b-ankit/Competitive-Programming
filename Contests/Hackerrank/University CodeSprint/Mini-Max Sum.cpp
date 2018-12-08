#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
	LL a[5],i,ma,mi,sum=0;
	for(i=0;i<5;i++)
    {
        cin>>a[i];
        if(i==0)
            ma=a[0];
        if(i==0)
            mi=a[0];
        if(a[i]>ma)
            ma=a[i];
        if(a[i]<mi)
            mi=a[i];
        sum+=a[i];
    }
    cout<<sum-ma<<" "<<sum-mi;
	return 0;
}
