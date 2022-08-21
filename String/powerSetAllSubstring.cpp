#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "AnanadkumarSatapathy";
    int n = s.length();
    string s2 = "";
    for(int num = 0;num<(1<<n)-1;num++)
    {
        for(int i=0;i<n;i++){
            if(num&(1<<i))
                {
                    s2+=s[i];
                }
            cout<<s2<<endl;
        }
    }
}



