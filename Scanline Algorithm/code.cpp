#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int> v(n+1,0);
    int query;
    cin >> query;
    while(query)
    {
        query--;
        int l,r,x;
        cin >> l>> r >> x;
        v[l]+=x;
        v[r+1]-=x;
    }
    int currSum=0;
    int finalArray[n];
    for(int i=0;i<n;i++)
    {
        currSum+=v[i];
        finalArray[i]=currSum+arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout << finalArray[i] << " " ;
    }
    return 0;
}
