#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int n, arr[100000] = {0};
int idx[201][100005] = {0,};
char names[100000][101];
int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        scanf("%s",names[i]);
        int front = 0;
        while (idx[arr[i]][front] != 0)
        {
            front++;
        }
        idx[arr[i]][front] = i + 1;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n;)
    {
        int front = 0;
        while (idx[arr[i]][front] != 0)
        {
            printf("%d ",arr[i]);
            printf("%s\n", names[idx[arr[i]][front] - 1]);            
            front++;
        }
        i+=front;
    }
}