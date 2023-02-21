#include <iostream>
using namespace std;
int num[100000];
long long cumulativeSum[100001]={0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cumulativeSum[0]=0;
    for(int i=1;i<=n;i++)
    {
        cumulativeSum[i]=cumulativeSum[i-1]+num[i-1];
    }
    for(int j=0;j<m;j++)
    {
        int start,end;
        cin>>start>>end;
        cout<<cumulativeSum[end]-cumulativeSum[start-1]<<"\n";
    }
}