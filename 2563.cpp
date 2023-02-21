#include <iostream>
using namespace std;
int main()
{
    int n,mat[100][100]={0},count=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        for(int j=b;j<10+b;j++)
        {
            for(int k=a;k<10+a;k++)
            {
                mat[j][k]=1;
            }
        }
    }
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(mat[i][j]==1)
            {
                count++;
            }
        }
    }
    cout<<count;
}