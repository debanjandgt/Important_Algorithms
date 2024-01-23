#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int,int> m;
    int t=0;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i == 0)
        {
            m[i]++;
            n/=i;
        }
    }
    if(n>=2)
    m[n]++;
    
    int ans=1;
    for(auto it:m)
    {
        int a1=it.first;
        int a2=it.second;
        ans=ans*(pow(a1,a2)-pow(a1,(a2-1)));
    }
    cout << ans << endl;
    
}
