#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
// sieve algorithm
vector<bool> isPrime(N,1);


int main()
{
    isPrime[0]=isPrime[1]=false;
    for(int i = 2;i<N;i++ )
        if(isPrime[i]==true)
            for(int j = 2*j;j<N;j+=i){
                isPrime[j]=false;
            }
        int t;
        cin>>t;
        while(t--){
                int num;
                cin>>num;
                if(isPrime[num]==true)
                    cout<<"Prime\n";
                else
                    cout<<"not prime\n";
        }
    return 0;
}