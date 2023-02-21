#include <iostream>
using namespace std;
int min(int a, int b, int c)
{
    int arr[3], min = 99999;
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
int d[9000001][2] = {0};
int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (d[i * 3][0] > d[i][0] + 1 || d[i * 3][0] == 0)
        {
            d[i * 3][0] = d[i][0] + 1;
            d[i*3][1]=i;
        }
        if (d[i * 2][0] > d[i][0] + 1 || d[i * 2][0] == 0)
        {
            d[i * 2][0] = d[i][0]+1;
            d[i*2][1]=i;
        }
        if(d[i+1][0]>d[i][0]+1||d[i+1][0]==0)
        {
            d[i+1][0]=d[i][0]+1;
            d[i+1][1]=i;
        }
    }
    cout<<d[n][0]<<"\n";
    int k=n;
    for(int i=0;i<d[n][0]+1;i++)
    {
        cout<<k<<" ";
        k=d[k][1];
    }
}