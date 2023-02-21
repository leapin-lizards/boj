#include <iostream>
using namespace std;
int main()
{
    int n,arr[100],max=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    for(int i=2;i<max;i++)
    {
        int rem=arr[0]%i;
        bool isAns=true;
        for(int j=1;j<n;j++)
        {
            if(arr[j]%i!=rem)
            {
                isAns=false;
            }
        }
        if(isAns)
        {
            cout<<i<<" ";
        }
    }
}