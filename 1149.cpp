#include <iostream>
#include <vector>
using namespace std;
int min(int a,int b,int c)
{
    int res=999999;
    int arr[3];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    for(int i=0;i<3;i++)
    {
        if(arr[i]<res)
            res=arr[i];
    }
    return res;
}
int main()
{
    int d[1000][3];
   int cost[1000][3];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j ++)
        {
            int inp;
            cin >> inp;
            cost[i][j]=inp;
        }
    }
    d[0][0]=cost[0][0];
    d[0][1]=cost[0][1];
    d[0][2]=cost[0][2];
    for(int i=1;i<n;i++)
    {
        d[i][0]=min(d[i-1][1],d[i-1][2])+cost[i][0];
        d[i][1]=min(d[i-1][2],d[i-1][0])+cost[i][1];        
        d[i][2]=min(d[i-1][1],d[i-1][0])+cost[i][2];
    }
    cout<<min(d[n-1][0],d[n-1][1],d[n-1][2]);
}