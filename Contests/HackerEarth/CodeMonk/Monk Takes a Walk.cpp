#include <bits/stdc++.h>
using namespace std;
#define LL long long

bool vowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        return true;
    return false;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
    {
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<s.size();i++)
            if(vowel(s[i]))
                cnt++;
        cout<<cnt<<endl;
    }
	return 0;
}
