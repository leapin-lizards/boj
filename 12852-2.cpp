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
int main()
{
    int n;
    int d[1000001] = {0};
    cin >> n;
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i * 3] > d[i] + 1 || d[i * 3] == 0)
        {
            d[i * 3] = d[i] + 1;
        }
        if (d[i * 2] > d[i] + 1 || d[i * 2] == 0)
        {
            d[i * 2] = d[i]+1;
        }
        if(d[i+1]>d[i]+1||d[i-1]==0)
        {
            d[i+1]=d[i]+1;
        }
    }
    cout<<d[n];
}