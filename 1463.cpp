#include <iostream>
using namespace std;
int arr[1000001];
int min(int a,int b,int c)
{
    int res=999999;
    int val[3];
    val[0]=a;
    val[1]=b;
    val[2]=c;
    for(int i=0;i<3;i++)
    {
        if(val[i]<res)
        {
            res=val[i];
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            if (i % 2 == 0)
            {
                arr[i] = min(arr[i / 3] + 1, arr[i / 2] + 1, arr[i - 1] + 1);
            }
            else
            {
                arr[i] = min(arr[i / 3] + 1, arr[i - 1] + 1);
            }
        }
        else
        {
            if (i % 2 == 0)
            {
                arr[i] = min(arr[i / 2] + 1, arr[i - 1] + 1);
            }
            else
            {
                arr[i] = arr[i-1]+1;
            }
        }
    }
    cout<<arr[n];
}