#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> sieve(25,1);
    for(int i=2;i*i<=25;i++)
    {
        if(sieve[i] == 1)
        for(int j=i*i;j<=25;j+=i)
        {
            sieve[j]=0;
        }
    }
    cout << "Prime Numbers in the range of 1 to 25 are " << endl; 
    for(int i = 2 ;i<25;i++)
    {
        if(sieve[i] == 1)
        cout << i << " " ;
    }
}
