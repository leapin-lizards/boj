#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0, min = 9999, max = -9999, arr[500000] = {0}, median, mode, check[9999] = {0}, cvar = 0;
    double average;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        sum += inp;
        if (min > inp)
        {
            min = inp;
        }
        if (max < inp)
        {
            max = inp;
        }
        arr[i] = inp;
    }
    average = (double)sum / n;
    average = floor(average + 0.5);
    sort(arr, arr + n);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";
    median = arr[((n + 1) / 2)-1];
    for (int i = 0; i < n; i++)
    {
        check[arr[i]+4000]++;
    }
    int max2 = -9999;
    for (int i = 0; i < 9999; i++)
    {
        if (max2 < check[i])
        {
            max2 = check[i];
        }
    }
    for (int i = 0; i < 9999; i++)
    {
        if (check[i] == max2)
        {
            check[i] = -1;
            cvar++;
        }
    }
    for (int i = 0; i < 9999; i++)
    {
        if (check[i] == -1)
        {
            if (cvar >= 2)
            {
                cvar=1;
            }
            else
            {
                mode=i-4000;
                break;
            }
        }
    }
    cout<<average<<"\n"<<median<<"\n"<<mode<<"\n"<<max-min;
}