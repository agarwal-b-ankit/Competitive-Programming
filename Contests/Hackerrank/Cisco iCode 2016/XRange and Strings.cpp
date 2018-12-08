#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;


int main()
{
    int t;
    cin>>t;
	while(t-->0)
    {
        string a,b;
        cin>>a>>b;
        int pos=0,flag=0,i;
        for(i=0;i<a.size();i++)
        {
            if(pos<b.size() && a[i]==b[pos])
                pos++;
            else if( (i>0 && a[i]==a[i-1])||(i<a.size()-1 && a[i]==a[i+1]) )
            {}
            else
            {
                flag=1;
                break;
            }
        }
        if(a.size()<b.size() || flag==1 || pos<b.size())
            cout<<"NO";
        else
            cout<<"YES";
        cout<<endl;
    }
	return 0;
}

