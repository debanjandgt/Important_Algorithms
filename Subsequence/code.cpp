#include<bits/stdc++.h>
using namespace std;

void sub(vector<vector<int>>& ans,vector<int> v,vector<int> arr,int i)
{
    if(i == arr.size())
    {
        ans.push_back(v);
        return;
    }
    else
    {
        v.push_back(arr[i]);
        sub(ans,v,arr,i+1);
        v.pop_back();
        sub(ans,v,arr,i+1);
    }
}

int main()
{
    vector<int> arr={3,-4,5};
    vector<vector<int>> ans;
    vector<int> v;
    int i=0;
    sub(ans,v,arr,i);
    
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
