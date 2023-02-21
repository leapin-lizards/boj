#include <iostream>
using namespace std;
int main()
{
    int n,m,arr[100],min=9999999;
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(i==j||i==k||j==k)
                    continue;
                if(arr[i]+arr[j]+arr[k]>m)
                    continue;
                if(m-(arr[i]+arr[j]+arr[k])<min)
                {
                    min=m-(arr[i]+arr[j]+arr[k]);
                }
            }
        }
    }
    cout<<m-min;
}