#include <iostream>
using namespace std;
int main()
{
    int n,val[300];
    int d[300][3];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    d[1][1]=val[0];
    d[1][2]=-100000;
    d[2][1]=val[1];
    d[2][2]=val[0]+val[1];
    for(int i=3;i<=n;i++)
    {
        d[i][1]=max(d[i-2][1],d[i-2][2])+val[i-1];
        d[i][2]=d[i-1][1]+val[i-1];
    }
    cout<<max(d[n][1],d[n][2]);
}