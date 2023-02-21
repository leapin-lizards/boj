#include <iostream>
using namespace std;
int main()
{
    int test,mat[15][15]={0};
    cin>>test;
    for(int i=0;i<15;i++)
    {
        mat[0][i]=i+1;
    }
    for(int i=1;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            for(int k=0;k<j+1;k++)
            {
                mat[i][j]+=mat[i-1][k];
            }
        }
    }
    for(int i=0;i<test;i++)
    {
        int k,n;
        cin>>k;
        cin>>n;
        cout<<mat[k][n-1]<<"\n";        
    }
}