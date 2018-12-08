#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin>>q;
    while(q--)
        {
        long long x,cnt=0,c=0;
        cin>>x;
        while(x>0)
            {
            if(x%2==0)
                cnt+=pow(2,c);
            x/=2;
            c++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
